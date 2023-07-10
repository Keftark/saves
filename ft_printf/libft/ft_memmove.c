/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:11:26 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/18 14:32:06 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = -1;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
		while (++i < len)
			d[i] = s[i];
	return (dst);
}

/*int	main(void)
{
	char s[7] = "coucou";
	char d[] = "000000000000000000";
	printf("%s\n", (char *)ft_memmove(d, s, 7));
	for ( int i = 0; i < 18; i++)
		printf("%c", d[i]);
}*/
