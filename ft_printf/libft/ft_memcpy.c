/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:53:03 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/17 11:03:27 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dest;
	s = src;
	i = -1;
	while (++i < len)
		d[i] = s[i];
	return (dest);
}

/*int	main(void)
{
	char sdest[] = "0000000000";
	char ssrc[] = "Yolo";
	int j = 0;

	while (sdest[j])
		j++;
	ft_memcpy(sdest, ssrc, 3);
	for (int i = 0;i < j;i++)
		printf("%c", sdest[i]);
}*/
