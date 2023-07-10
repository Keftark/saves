/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:10:42 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/11 15:07:42 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*int strlength(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
int	main(int argc, char *argv[])
{
	char	str[20];
	size_t i = 0;
	
	printf("avant : %s\n", str);
	if (argc == 3)
	{
		i = ft_strlcpy(str, argv[1], 4);
		printf("apes : %s\n", str);
	}
}*/
