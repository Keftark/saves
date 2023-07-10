/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:03:42 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/17 16:44:43 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	total;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	if (nmemb == 0)
		nmemb = 1;
	if (size == 0)
		size = 1;
	total = size * nmemb;
	tmp = (char *)malloc(total);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, (total));
	return (tmp);
}

/*int	main(void)
{
	char *str;

	str = ft_calloc(2147, 2147);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	printf("%s", str);
	free(str);
}*/
