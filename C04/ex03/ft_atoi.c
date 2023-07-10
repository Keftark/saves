/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:55:22 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/18 15:43:55 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	pos;

	i = 0;
	nb = 0;
	pos = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pos = -pos;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i++] - 48;
	}
	return (nb * pos);
}

#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%d\n", ft_atoi(argv[1]));
	printf("%d", atoi(argv[1]));
}
