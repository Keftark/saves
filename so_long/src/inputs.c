/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:47:34 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/13 09:39:30 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit_game(data);
	else if ((keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
		&& data->can_move == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->imgs.empty,
			data->player.pos_x * 32 - 16, data->player.pos_y * 32 - 16);
		if (keysym == 119 && check_collision(data,
				data->player.pos_x, data->player.pos_y - 1) == 0)
			data->player.pos_y -= 1;
		else if (keysym == 97 && check_collision(data,
				data->player.pos_x - 1, data->player.pos_y) == 0)
			data->player.pos_x -= 1;
		else if (keysym == 115 && check_collision(data,
				data->player.pos_x, data->player.pos_y + 1) == 0)
			data->player.pos_y += 1;
		else if (keysym == 100 && check_collision(data,
				data->player.pos_x + 1, data->player.pos_y) == 0)
			data->player.pos_x += 1;
		mlx_put_image_to_window(data->mlx, data->win, data->player.sprite[0],
			data->player.pos_x * 32 - 16, data->player.pos_y * 32 - 16);
	}
	return (0);
}

void	check_collectibles(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->items)
	{
		if (data->collectibles[i].is_reachable == 0)
		{
			data->errors += write(1,
					"Error!\n\tItem not reachable!\n", 35);
			return ;
		}
		i++;
	}
}
