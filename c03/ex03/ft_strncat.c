/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:55:09 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/15 15:29:58 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[j] != '\0')
		j++;
	while (src[k] != '\0' && i < nb)
	{
		dest[j + k] = src[k];
		k++;
		i++;
	}
	dest[j + k] = '\0';
	return (dest);
}

/*int	ft_strlen(char *st)
{
	int	i;

	i = 0;
	while (st[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	unsigned int	i;
	char	*total;
	char	debut[] = "Je t'";
	char	fin[] = "ai pose une question !";

	i = ft_strlen(debut) + ft_strlen(fin);
	total = (char *) malloc(i);
	ft_strncat(total, debut, ft_strlen(debut));
	printf("%s", ft_strncat(total, fin, i));
	free(total);
}*/
