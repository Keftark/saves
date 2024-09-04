#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

char    *msgs[65535];
int     ids[65535];

fd_set read_fds, write_fds, all_fds;

int count = 0;
int max_fd = 0;

char buffer_read[1001];
char buffer_write[42];


int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

void    print_error(char *str)
{
    write(2, str, strlen(str));
    exit(1);
}

void    notify_all_clients(int client_fd, char *str)
{
    for (int fd = 0; fd <= max_fd; fd++)
    {
        if (FD_ISSET(fd, &write_fds) && fd != client_fd)
            send(fd, str, strlen(str), 0);
    }
}

void    register_client(int fd)
{
    if (fd > max_fd)
        max_fd = fd;
    FD_SET(fd, &all_fds);
    ids[fd] = count++;
    msgs[fd] = NULL;
    sprintf(buffer_write, "server: client %d just arrived\n", ids[fd]);
    notify_all_clients(fd, buffer_write);
}

void    remove_client(int fd)
{
    sprintf(buffer_write, "server: client %d just left\n", ids[fd]);
    notify_all_clients(fd, buffer_write);
    FD_CLR(fd, &all_fds);
    free(msgs[fd]);
    close(fd);
}

void    send_message(int fd)
{
    char *str;

    while (extract_message(&(msgs[fd]), &str))
    {
        sprintf(buffer_write, "client %d: ", ids[fd]);
        notify_all_clients(fd, buffer_write);
        notify_all_clients(fd, str);
        free(str);
    }
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int create_socket()
{
	max_fd = socket(AF_INET, SOCK_STREAM, 0); 
	if (max_fd < 0)
        print_error("Fatal Error\n");
    FD_SET(max_fd, &all_fds);
    return max_fd;
}

int main(int ac, char **av)
{
	int sockfd;
	struct sockaddr_in servaddr; 

    if (ac != 2)
        print_error("Wrong number of arguments\n");

	// socket create and verification
    FD_ZERO(&all_fds);
    sockfd = create_socket();
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        print_error("Fatal error\n");
	if (listen(sockfd, 10) != 0)
        print_error("Fatal error\n");

    while (42)
    {
        read_fds = write_fds = all_fds;

        if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0)
            print_error("Fatal Error\n");
        
        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (!FD_ISSET(fd, &read_fds))
                continue;
            if (fd == sockfd)
            {
                socklen_t addr_len = sizeof(servaddr);
                int client_fd = accept(sockfd, (struct sockaddr *)&servaddr, &addr_len);
                if (client_fd >= 0)
                {
                    register_client(client_fd);
                    break;
                }
            }
            else
            {
                int read_bytes = recv(fd, buffer_read, 1000, 0);
                if (read_bytes <= 0)
                {
                    remove_client(fd);
                    break;
                }
                buffer_read[read_bytes] = '\0';
                msgs[fd] = str_join(msgs[fd], buffer_read);
                send_message(fd);
            }
        }
    }
}
