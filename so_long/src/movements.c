/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:07:23 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/12 13:44:03 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ptnbr(int nbr)
{
	if (nbr > 9)
	{
		ptnbr(nbr / 10);
		ptnbr(nbr % 10);
	}
	else
	{
		nbr += 48;
		write(1, &nbr, 1);
	}
}

void	add_move(t_data *data)
{
	char	*str;
	char	*nbr;

	data->moves++;
	nbr = ft_itoa(data->moves);
	str = ft_strjoin("Moves: ", nbr);
	write(1, "\rMoves: ", 8);
	ptnbr(data->moves);
	render_rect(data, (t_rect){0, data->level_size.height * 32 + 20,
		128, 64, 0x000000});
	mlx_string_put(data->mlx, data->win, 16, data->level_size.height * 32 + 40,
		0xFFFFFF, str);
	free(str);
	free(nbr);
}

void	open_door(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs.door_open,
		data->door_pos_x * 32 + 16, data->door_pos_y * 32 + 16);
}

int	pickup_item(t_data *data, int x, int y)
{
	data->level[y - 1][x - 1] = '0';
	data->remaining_items--;
	if (data->remaining_items == 0)
		open_door(data);
	return (0);
}

int	check_collision(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	if (data->level[y - 1][x - 1] == '1')
		i = 1;
	else if (data->level[y - 1][x - 1] == 'C')
		i = pickup_item(data, x, y);
	else if (data->level[y - 1][x - 1] == 'E')
	{
		if (data->remaining_items > 0)
			i = 1;
		else
		{
			add_move(data);
			i = quit_game(data);
		}
	}
	else if (data->level[y - 1][x - 1] == 'X')
	{
		start_death_anim(data);
		i = 0;
	}
	if (i == 0)
		add_move(data);
	return (i);
}
