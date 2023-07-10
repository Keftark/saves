/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:03:32 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/17 10:09:42 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, s + i);
			i++;
		}
	}
}

/*void	ft_f(unsigned int i, char *str)
{
	*str = *str + i;
}

int	main(void)
{
	char digits[] = "00000";
	printf("before %s\n", digits);
	ft_striteri(digits, ft_f);
	printf("after %s\n", digits);
}*/
