/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:14:23 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/14 15:00:57 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	const char str[7] = "coucou";
	printf("%s", (const char *)ft_memchr(str, 111, 5));	
}*/
