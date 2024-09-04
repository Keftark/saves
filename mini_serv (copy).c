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

// on affiche un message d'erreur sur l'output d'erreur et on exit() le programme en precisant 1 = erreur
void    print_error(char *str)
{
    write(2, str, strlen(str));
    exit(1);
}


// on envoie a tous les clients un message
void    notify_all_clients(int client_fd, char *str)
{
    for (int fd = 0; fd <= max_fd; fd++)
    {
        if (FD_ISSET(fd, &write_fds) && fd != client_fd) // si fd est dans le set write_fds et s'il est different du client,
            send(fd, str, strlen(str), 0); // on envoie le message, sans flag (le 0).
    }
}

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;

    if (argc != 2)
        print_error("Wrong number of arguments\n");

	// socket create and verification
    FD_ZERO(&all_fds); // on clear all_fd. c'est comme un bzero
    max_fd = socket(AF_INET, SOCK_STREAM, 0); // on cree un socket. AF_INET = ipv4, SOCK_STREAM = tcp connexion
	if (max_fd < 0) // on check si la fonction a reussi. max_fd devrait etre au moins egal a 0 (ca commence par 0, puis 1, 2, etc.)
        print_error("Fatal error\n"); // si ca a echoue, on print une erreur (et exit(1))
    FD_SET(max_fd, &all_fds); // on ajoute max_fd a all_fds
    sockfd = max_fd;
	bzero(&servaddr, sizeof(servaddr)); // on fait un bzero de servaddr. reinitialisation

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; // on indique que le serveur est en ipv4
	// servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1 // on rentre l'adresse locale
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // on rentre l'adresse locale, la bonne ligne est dans le main donne
	servaddr.sin_port = htons(atoi(argv[1])); // on entre le port (c'est le premier argument qu'on entre en lancant le programme (8080, par exemple))
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) // si la tentative de connexion echoue
        print_error("Fatal error\n"); // on met une erreur
	if (listen(sockfd, 10) != 0) // si on n'arrive pas a ecouter le fd enregistre
        print_error("Fatal error\n"); // on met une erreur

    while (42) // on fait une boucle
    {
        read_fds = write_fds = all_fds; // on reinitialise les valeurs (all_fds a ete FD_ZERO plus haut, puis on a ajoute all_fds)

        if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0) // on verifie si tous les fd enregistres fonctionnent | nbre de fd, read, write, conditions exceptionnelles, on attend que tous les fd sont prets
            print_error("Fatal error\n"); // si non, on retourne une erreur
        
        for (int fd = 0; fd <= max_fd; fd++) // pour chaque fd
        {
            if (!FD_ISSET(fd, &read_fds)) // si le fd ne fait pas partie du set read_fds
                continue; // on passe a la prochaine iteration
            if (fd == sockfd) // si le fd correspond a celui enregistre dernierement, on va envoyer un message
            {
                socklen_t addr_len = sizeof(servaddr); // on stocke la taille de l'adresse serveur pour l'utiliser en pointeur en-dessous
                int client_fd = accept(sockfd, (struct sockaddr *)&servaddr, &addr_len); // accepte une connexion avec le sockfd, stocke l'adresse dans servaddr et la taille de servaddr dans addr_len. retourne un fd.
                if (client_fd >= 0) // si le client existe, donc si accept a fonctionne
                {
                    if (client_fd > max_fd) // si le client_fd est superieur a max_fd, donc pas encore enregistre (un peu bancal, comme explication)
                        max_fd = client_fd; // on met max_fd a la valeur du client_fd.
                    FD_SET(client_fd, &all_fds); // on ajoute client_fd a la liste all_fd
                    ids[client_fd] = count++; // le client a un identifiant correspondant au nombre de clients qui se sont connectes, en commencant par 0
                    msgs[client_fd] = NULL; // on initialise le buffer de messages a NULL
                    sprintf(buffer_write, "server: client %d just arrived\n", ids[client_fd]); // on enregistre un texte dans buffer_write
                    notify_all_clients(client_fd, buffer_write); // puis on envoie cette string a tout le monde
                    break; // on break, parce qu'on a fini la boucle
                }
            }
            else // ici on va receptionner les messages seulement
            {
                int read_bytes = recv(fd, buffer_read, 1000, 0); // on receptionne un message qu'on va mettre dans buffer_read
                if (read_bytes <= 0) // si la lecture a echoue ou si le texte est vide
                {
                    sprintf(buffer_write, "server: client %d just left\n", ids[fd]); // on ecrit que le client est parti dans buffer_write
                    notify_all_clients(fd, buffer_write); // on envoie le message a tout le monde
                    FD_CLR(fd, &all_fds); // on clear le all_fds
                    free(msgs[fd]); // on free les messages enregistres
                    close(fd); // on ferme le fd
                    break; // on break, pour terminer la boucle
                }
                buffer_read[read_bytes] = '\0'; // ici un message a bien ete recu, on le termine par un \0
                msgs[fd] = str_join(msgs[fd], buffer_read); // on join le message recu a tous les autres de ce fd
                char *str;

                while (extract_message(&(msgs[fd]), &str)) // tant qu'on peut mettre un message dans str
                {
                    sprintf(buffer_write, "client %d: ", ids[fd]); // on enregistre le client dans buffer_write (client 1:)
                    notify_all_clients(fd, buffer_write); // on envoie (client 1:) a tout le monde
                    notify_all_clients(fd, str); // puis on envoie le message
                    free(str); // on free le message une fois envoye
                }
            }
        }
    }
}