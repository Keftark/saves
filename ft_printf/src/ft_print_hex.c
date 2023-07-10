/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:37:13 by cpothin           #+#    #+#             */
/*   Updated: 2023/05/16 14:40:06 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_ptchar(num + '0');
		else
		{
			if (format == 'x')
				ft_ptchar(num - 10 + 'a');
			if (format == 'X')
				ft_ptchar(num - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int val, const char format)
{
	if (val == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_put_hex(val, format);
	return (ft_hex_len(val));
}
