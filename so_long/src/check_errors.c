/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 08:51:54 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/14 08:55:44 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_errors(t_data *data, char *level)
{	
	int	i;

	if (check_walls(data->level) == 0)
		data->errors += write(1, "Error\n\tWalls!\n", 14);
	i = 0;
	while (i < data->items)
	{
		data->level = ft_split(level);
		check_access(data, data->collectibles[i].pos_x,
			data->collectibles[i].pos_y, i);
		free_level(data);
		i++;
	}
	data->level = ft_split(level);
	check_access(data, data->player.pos_x - 1,
		data->player.pos_y - 1, -1);
	free_level(data);
	data->level = ft_split(level);
	check_collectibles(data);
	if (check_items(data->level) == -1)
		data->errors += write(1, "Error\n\tNo item!\n", 16);
	if (data->is_resolvable == 0)
		data->errors += write(1, "Error\n\tNo access!\n", 18);
	if (check_doubles(data->level) == 1)
		data->errors += write(1, "Error\n\tProblem with player or exit!\n", 36);
}
