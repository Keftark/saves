/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anims.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 08:19:17 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/09 14:20:41 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_can_quit(t_data *data)
{
	int	x;
	int	y;
	int	o;

	x = 0;
	y = 0;
	o = 1;
	while (data->level[y])
	{
		while (data->level[y][x])
		{
			if (data->level[y][x] != -1)
				o = 0;
			x++;
		}
		y++;
	}
	if (o == 1)
	{
		data->can_move = 1;
		quit_game(data);
	}
	return (o);
}

void	render_at_pos(t_data *data, int x, int y)
{
	render_rect(data, (t_rect){x * 32 + 16, y * 32 + 16,
		32, 32, 0x000000});
}

int	get_next_pos(t_data *data, int posx, int posy)
{
	check_can_quit(data);
	if (posy - 1 > -1 && data->level[posy - 1][posx] != -1)
	{
		data->level[posy - 1][posx] = -1;
		render_at_pos(data, posx, posy - 1);
	}
	if (posx - 1 > -1 && data->level[posy][posx - 1] != -1)
	{
		data->level[posy][posx - 1] = -1;
		render_at_pos(data, posx - 1, posy);
	}
	if (posy + 1 < data->level_size.height && data->level[posy + 1][posx] != -1)
	{
		data->level[posy + 1][posx] = -1;
		render_at_pos(data, posx, posy + 1);
	}
	if (posx + 1 < data->level_size.width && data->level[posy][posx + 1] != -1)
	{
		data->level[posy][posx + 1] = -1;
		render_at_pos(data, posx + 1, posy);
	}
	return (1);
}

void	find_next_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			if (data->level[y][x] == -1)
				get_next_pos(data, x, y);
			x++;
		}
		y++;
	}
}

int	death_anim(t_data *data)
{
	data->cur_frame++;
	if (data->cur_frame > 2400)
	{
		data->level[data->door_pos_y][data->door_pos_x] = -1;
		render_rect(data, (t_rect){data->door_pos_x * 32 + 16,
			data->door_pos_y * 32 + 16, 32, 32, 0x000000});
		find_next_pos(data);
		data->cur_frame = 0;
	}
	return (0);
}
