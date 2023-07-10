/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:58:38 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/15 15:28:47 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	char	*total;
	char	debut[] = "Comment ";
	char	fin[] = "vas-tu ?";

	total = (char *) malloc(ft_strlen(debut) + ft_strlen(fin) + 2);
	printf("%s  <-- debut\n", debut);
	printf("%s  <-- fin\n", fin);
	ft_strcat(total, debut);
	printf("%s  <-- apres concatenation", ft_strcat(total, fin));
	free(total);
	return (0);
}*/
