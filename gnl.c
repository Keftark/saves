#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*	retourne 1 si la ligne se termine par un \n
	retourne 0 s'il n'y a pas de caracteres ou si la ligne se termine par un \0
*/
int ft_check_line(char *dest)
{
	int i;

	i = 0;
	if (!dest)
		return (0);
	while(dest[i] && dest[i] != '\n')
		i++;
	if (dest[i] == '\n')
		return (1);
	return (0);
}

int ft_strlen_line(char *dest)
{
	int i;

	i = 0;
	if (!dest)
		return (0);
	while (dest[i] && dest[i] != '\n')
		i++;
	return (i);
}

int ft_strlen(char *dest)
{
	int i;

	i = 0;
	if (!dest)
		return (0);
	while (dest[i])
		i++;
	return (i);
}

char *ft_join_line(char *src, char *buff)
{
	int i;
	int j;
	char *dest; // nouvelle chaine sur laquelle on va mettre les deux parties du texte

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen_line(buff) + ft_strlen(src) + 2)); // on fait un malloc en prenant en compte les deux chaines a ajouter. + un \n et un \0
	if (src) // s'il y a une chaine a la base
	{
		while (src[i]) // on parcourt la chaine
		{
			dest[i] = src[i]; // et on copie sur le dest
			i++;
		}
		free (src); // puis on free la src
	}
	while (buff[j] && buff[j] != '\n') // tant qu'on n'est pas a la fin de la ligne du buff
		dest[i++] = buff[j++]; // on copie le contenu de buff sur dest
	dest[i] = '\n'; // puis on ajoute un \n (demande par le sujet)
	if (buff[j] == '\n') // s'il y a un \n a la base, on incremente i
		i++;
	dest[i] = '\0'; // on ferme la chaine dest
	if (dest[0] == '\0') // s'il n'y a rien sur la chaine de base
	{
		free(dest); // on free et on retourne NULL
		return(NULL);
	}
	return (dest); // sinon on retourne la ligne
}

/*
	On passe la premiere ligne et on garde le reste.
*/
void ft_cut_line(char *dst)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i] && dst[i] != '\n') // tant qu'on ne rencontre pas un \n ou \0, on incremente i
		i++;
	if (dst[i] == '\n') // si la chaine se termine par un \n, on incremente le i
		i++;
	while (dst[i]) // on decale tous les caracteres passes au debut de la chaine jusqu'a \0
		dst[j++] = dst[i++];
	dst[j] = '\0'; // et on ferme la chaine
}

char *get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	int i;
	char *dest;

	i = 1;
	dest = NULL; // on met dest a NULL pour pouvoir retourner NULL s'il n'y a rien a join
	if (BUFFER_SIZE <= 0 || fd < 0) // on verifie que le buffersize et le fd ont de bonnes valeurs, sinon on retourne NULL
		return (NULL);
	if (ft_check_line(buff) == 1) // si une ligne est deja enregistree et se termine par un \n
	{
		ft_cut_line(buff); // on coupe jusqu'au \n ou \0
		dest = ft_join_line(dest, buff); // on isole la premiere ligne de buff sur dest (jusqu'au \n)
	}
	while (i > 0 && ft_check_line(buff) == 0) // tant que buff ne se termine pas par un \n
	{
		i = read(fd, buff, BUFFER_SIZE); // on lit et on met dans buff
		printf("%d\n", i);
		if (i <= 0) // si la lecture echoue ou se termine, on retourne dest (i retourne 0 seulement si la lecture termine le fichier, et -1 si elle echoue)
			return (dest);
		buff[i] = '\0'; // si la lecture n'echoue pas, on ferme la chaine de caracteres lue
		dest = ft_join_line(dest, buff); // puis on join dans dest ce qu'on a lu
	}
	return (dest);
}

int main()
{
    int i;

    char *src;
    i = open("test.txt", O_RDONLY);
    src = get_next_line(i);
    printf("%s", src);
    if (src)
        free(src);
    src = get_next_line(i);
    printf("%s", src);
    if (src)
        free(src);
    src = get_next_line(i);
    printf("%s", src);
    if (src)
        free(src);
    src = get_next_line(i);
    printf("%s", src);
    if (src)
        free(src);
    src = get_next_line(i);
    printf("%s", src);
    if (src)
        free(src);


}
/*
int main()
{
	int i;
	
	i = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	
}*/
/*
int    main(void)
{
    char *line;
    int     fd;

    fd = open("test.txt", O_RDONLY);

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}*/

//gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=255 gnl.c
