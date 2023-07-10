/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:51:44 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/14 08:57:06 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_items_positions(t_data *data)
{
	int	x;
	int	y;
	int	items;

	y = 0;
	data->collectibles = (t_coll *)malloc(sizeof(t_coll) * data->items);
	if (!data->collectibles)
		return ;
	items = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			if (data->level[y][x] == 'C')
			{
				data->collectibles[items].is_reachable = 0;
				data->collectibles[items].pos_x = x;
				data->collectibles[items].pos_y = y;
				items++;
			}
			x++;
		}
		y++;
	}
}

void	set_level_size(char *str, t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	data->level_size.width = 0;
	data->level_size.height = 0;
	while (str[i])
	{
		if (str[i] == '\n' && data->level_size.width == 0)
			data->level_size.width = i;
		if (str[i] == '\n' || str[i] == '\0')
			y++;
		i++;
	}
	data->level_size.height = y;
}

void	read_level(char *path, t_data *data)
{
	int		fd;
	int		rd_bytes;
	char	*level;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		write(1, "Map error\n", 11);
	level = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!level)
		return ;
	rd_bytes = read(fd, level, BUFFER_SIZE);
	if (rd_bytes == -1)
		return (free(level));
	level[rd_bytes] = '\0';
	close(fd);
	set_level_size(level, data);
	data->level = ft_split(level);
	init_player(data);
	check_errors(data, level);
	free(level);
}

void	*check_frame(t_data *data, int x, int y)
{
	void	*f;
	char	c;

	c = data->level[y][x];
	if (c == '1')
		f = data->imgs.wall;
	else if (c == '0')
		f = data->imgs.empty;
	else if (c == 'C')
		f = data->imgs.item;
	else if (c == 'E')
		f = data->imgs.exit;
	else if (c == 'P')
		f = data->player.sprite[0];
	else if (c == 'X')
		f = data->imgs.enemy;
	return (f);
}

int	parse_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->level[y])
	{
		x = 0;
		while (data->level[y][x])
		{
			mlx_put_image_to_window(data->mlx, data->win,
				check_frame(data, x, y), x * SIZE + SIZE / 2,
				y * SIZE + SIZE / 2);
			if (data->level[y][x] == 'E')
			{
				data->door_pos_x = x;
				data->door_pos_y = y;
			}
			x++;
		}
		y++;
	}
	add_move(data);
	return (0);
}
