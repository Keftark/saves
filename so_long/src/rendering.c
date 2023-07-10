/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:26:19 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/12 13:43:17 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	animate_player(t_data *data)
{
	data->cur_frame++;
	if (data->cur_frame > 20000)
	{
		data->player_frame++;
		if (data->player_frame > 3)
			data->player_frame = 0;
		mlx_put_image_to_window(data->mlx, data->win,
			data->player.sprite[data->player_frame],
			data->player.pos_x * 32 - 16, data->player.pos_y * 32 - 16);
		data->cur_frame = 0;
	}
	return (0);
}

void	load_images(t_data *data)
{
	int	size;

	size = SIZE;
	data->imgs.wall = mlx_xpm_file_to_image(data->mlx,
			"imgs/wall.xpm", &size, &size);
	data->imgs.empty = mlx_xpm_file_to_image(data->mlx,
			"imgs/empty.xpm", &size, &size);
	data->player.sprite[0] = mlx_xpm_file_to_image(data->mlx,
			"imgs/pika1.xpm", &size, &size);
	data->player.sprite[1] = mlx_xpm_file_to_image(data->mlx,
			"imgs/pika2.xpm", &size, &size);
	data->player.sprite[2] = mlx_xpm_file_to_image(data->mlx,
			"imgs/pika3.xpm", &size, &size);
	data->player.sprite[3] = mlx_xpm_file_to_image(data->mlx,
			"imgs/pika4.xpm", &size, &size);
	data->imgs.enemy = mlx_xpm_file_to_image(data->mlx,
			"imgs/enemy.xpm", &size, &size);
	data->imgs.item = mlx_xpm_file_to_image(data->mlx,
			"imgs/item.xpm", &size, &size);
	data->imgs.exit = mlx_xpm_file_to_image(data->mlx,
			"imgs/exit.xpm", &size, &size);
	data->imgs.door_open = mlx_xpm_file_to_image(data->mlx,
			"imgs/exit_open.xpm", &size, &size);
	data->win = mlx_new_window(data->mlx, data->level_size.width * SIZE + SIZE,
			data->level_size.height * SIZE + SIZE + 24, "PikAdventures");
}

void	start_death_anim(t_data *data)
{
	mlx_loop_hook(data->mlx, &death_anim, data);
	data->can_move = 0;
}
