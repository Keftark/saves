/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 08:56:07 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/14 14:19:12 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_first_last_rows(char **level)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (level[0][x])
	{
		if (level[0][x] != '1')
			return (0);
		x++;
	}
	while (level[y])
		y++;
	y--;
	x = 0;
	while (level[y][x])
	{
		if (level[y][x] != '1')
			return (0);
		x++;
	}
	return (x - 1);
}

int	check_walls(char **level)
{
	int	x;
	int	y;
	int	length;

	y = 0;
	length = check_first_last_rows(level);
	if (length == 0)
		return (0);
	while (level[y])
	{
		x = 0;
		if (level[y][x] != '1')
			return (0);
		while (level[y][x])
			x++;
		if (x - 1 != length || level[y][x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void	check_access(t_data *data, int x, int y, int is_item)
{
	if (x < 0 || x > data->level_size.width)
		return ;
	if (y < 0 || y > data->level_size.height)
		return ;
	if (data->is_resolvable == 1 || !data->level[y][x]
		|| data->level[y][x] == '1' || data->level[y][x] == 'X')
		return ;
	if (data->level[y][x] == 'E')
	{
		if (is_item > -1)
			data->collectibles[is_item].is_reachable = 1;
		else if (data->is_resolvable == 0)
			data->is_resolvable = 1;
		return ;
	}
	data->level[y][x] = '1';
	check_access(data, x + 1, y, is_item);
	check_access(data, x, y - 1, is_item);
	check_access(data, x - 1, y, is_item);
	check_access(data, x, y + 1, is_item);
}

int	check_doubles(char **level)
{
	int	player;
	int	exit;
	int	x;
	int	y;

	player = 0;
	exit = 0;
	y = 0;
	while (level[y])
	{
		x = 0;
		while (level[y][x])
		{
			if (level[y][x] == 'P')
				player++;
			else if (level[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (player != 1 || exit != 1)
		return (1);
	return (0);
}

int	check_items(char **level)
{
	int	items;
	int	x;
	int	y;

	y = 0;
	items = 0;
	while (level[y])
	{
		x = 0;
		while (level[y][x])
		{
			if (level[y][x] == 'C')
				items++;
			x++;
		}
		y++;
	}
	if (items == 0)
		return (0);
	return (1);
}
