/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:11:11 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/13 09:06:30 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			if (data->level[y][x] == 'P')
			{
				data->player.pos_x = x + 1;
				data->player.pos_y = y + 1;
			}
			else if (data->level[y][x] == 'C')
				data->items++;
			x++;
		}
		y++;
	}
	data->remaining_items = data->items;
	set_items_positions(data);
}

void	init_data(t_data *data, char *str)
{
	char	*path;

	data->moves = -1;
	data->items = 0;
	data->is_resolvable = 0;
	data->remaining_items = 0;
	data->cur_frame = 0;
	data->player_frame = 0;
	data->errors = 0;
	data->can_move = 1;
	data->mlx = mlx_init();
	path = ft_strjoin("maps/", str);
	read_level(path, data);
	free(path);
	load_images(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (0);
	init_data(&data, argv[1]);
	if (!data.level || data.errors > 0)
		return (quit_game(&data));
	parse_map(&data);
	mlx_loop_hook(data.mlx, &animate_player, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, 17, 0, &quit_game, &data);
	mlx_loop(data.mlx);
	quit_game(&data);
}
