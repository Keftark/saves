/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 08:58:35 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/16 08:51:35 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_level(t_data *data)
{
	int	i;

	i = 0;
	while (data->level[i])
		free(data->level[i++]);
	free(data->level);
	data->level = NULL;
}

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->imgs.exit);
	mlx_destroy_image(data->mlx, data->imgs.wall);
	mlx_destroy_image(data->mlx, data->player.sprite[0]);
	mlx_destroy_image(data->mlx, data->player.sprite[1]);
	mlx_destroy_image(data->mlx, data->player.sprite[2]);
	mlx_destroy_image(data->mlx, data->player.sprite[3]);
	mlx_destroy_image(data->mlx, data->imgs.empty);
	mlx_destroy_image(data->mlx, data->imgs.enemy);
	mlx_destroy_image(data->mlx, data->imgs.item);
	mlx_destroy_image(data->mlx, data->imgs.door_open);
}

int	quit_game(t_data *data)
{
	free_level(data);
	free(data->collectibles);
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
