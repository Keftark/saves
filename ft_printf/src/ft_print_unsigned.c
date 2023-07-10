/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:18:48 by cpothin           #+#    #+#             */
/*   Updated: 2023/04/20 16:11:21 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	nb_count(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char				*str;
	int					i;
	unsigned long int	nb;

	nb = n;
	i = nb_count(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = 0;
	if (nb == 0)
	{
		free(str);
		str = ft_calloc(2, sizeof(char));
		str[0] = 48;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int u)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_uitoa(u);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}
