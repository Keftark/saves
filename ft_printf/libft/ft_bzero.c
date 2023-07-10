/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:29:09 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/17 09:11:00 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t j)
{
	char	*st;
	size_t	i;

	st = str;
	i = 0;
	while (i < j)
	{
		st[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char    str[4] = {"abc"};

	ft_bzero(str, 2);
	printf("Alpha: ");
	for (int i = 0;i < 4; i++)
		printf("%c", str[i]);
	printf("\nNumeric: ");
	for (int i = 0;i < 4; i++)
		printf("%d", str[i]);
}*/
