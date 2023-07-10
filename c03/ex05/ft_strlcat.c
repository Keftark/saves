/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:51 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/16 14:14:20 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	l;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	l = ft_strlen(src) + ft_strlen(dest);
	while (dest[j] && j < size)
		j++;
	while (src[k] && i < size)
	{
		dest[j + k] = src[k];
		i++;
		k++;
	}
	dest[j + k] = '\0';
	return (l);
}

/*#include <stdlib.h>
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	*total;
	char	debut[] = "Hey";
	char	fin[] = " comment vas-tu ?";

	total = (char *)malloc(ft_strlen(debut) + ft_strlen(fin) + 1);
	*total = '\0';
	ft_strlcat(total, debut, ft_strlen(debut));
//	printf("%ld caracteres dans la chaine\n", strlcat(total, fin, ft_strlen(fin)));
	printf("%u caracteres dans la chaine\n", ft_strlcat(total, fin, 50));
	printf("%s\n", total);
	free(total);
}*/
