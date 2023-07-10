/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:26:29 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/14 11:53:56 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	char	*ptr;

	ptr = dest;
	while (len-- > 0)
		*ptr++ = val;
	return (dest);
}

/*int	main(void)
{
	char str[10] = "";
	
	ft_memset(str, 0, 5);
	printf("%s", str);
}*/
