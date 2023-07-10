/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:04:59 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/20 16:08:05 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t s)
{
	size_t	ld;
	size_t	i;

	ld = ft_strlen(dest);
	if (s <= ld)
		return (s + ft_strlen(src));
	i = 0;
	while (src[i] && ld + 1 < s)
		dest[ld++] = src[i++];
	dest[ld] = '\0';
	return (ld + ft_strlen(&src[i]));
}

/*int	main(void)
{
	char	base[20] = "Hey ";
	char	base2[20] = "Hey ";
	char	add[20] = "coucou";
	char	add2[20] = "coucou";
	(void)ft_strlcat(base, add, 10);
	(void)strlcat(base2, add2, 10);
	printf("%s\n", base);
	printf("%s", base2);
}*/
