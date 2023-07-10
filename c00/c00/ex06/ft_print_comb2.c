/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:24:28 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/07 10:50:32 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('0');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_putall(int nb1, int nb2)
{
	if (nb1 < 10)
		ft_putchar('0');
	ft_putnbr(nb1);
	ft_putchar(' ');
	if (nb2 < 10)
		ft_putchar('0');
	ft_putnbr(nb2);
	if (!(nb1 == 98 && nb2 == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i != 99)
	{
		while (j != 100)
		{
			ft_putall(i, j);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	main(void)
{
	ft_print_comb2();
}
