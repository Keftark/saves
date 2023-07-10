/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:30:44 by cpothin           #+#    #+#             */
/*   Updated: 2023/03/21 15:02:22 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_putnbr(unsigned short nb)
{
	char	c;

	c = ' ';
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + 48;
		write(1, &c, 1);
	}
}

static void	print_bsq(t_data *d)
{
	(void)!write(1, &d->map[d->n], d->nbr_lines * (d->len_lines + 1));
}

static void	print_debug(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;

	write(1, "\n", 1);
	y = 0;
	while (y < d->nbr_lines)
	{
		x = 0;
		while (x < d->len_lines)
		{
			ft_putnbr(matrix[y][x]);
			x++;
		}
		y++;
		write(1, "\n", 1);
	}
}

static void	paint_bsq(t_data *d, unsigned short **matrix)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	top_left_x;
	unsigned int	top_left_y;

	top_left_x = d->bsq_x - matrix[d->bsq_y][d->bsq_x] + 1;
	top_left_y = d->bsq_y - matrix[d->bsq_y][d->bsq_x] + 1;
	y = 0;
	while (y <= d->nbr_lines)
	{
		x = 0;
		while (x <= d->len_lines)
		{
			if ((y >= top_left_y && y <= d->bsq_y)
				&& (x >= top_left_x && x <= d->bsq_x))
				d->map[(y * (d->len_lines + 1)) + x + d->n] = d->filler;
			x++;
		}
		y++;
	}
}

void	display_bsq(t_data *d, unsigned short **matrix)
{
	paint_bsq(d, matrix);
	print_bsq(d);
	if (DEBUG != 0)
		print_debug(d, matrix);
}
