/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:23:41 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/14 08:53:21 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>

# define WIN_H 600
# define WIN_W 800
# define SIZE 32
# define BUFFER_SIZE 1024

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	void	*sprite[4];

}	t_player;

typedef struct s_collectible
{
	int	pos_x;
	int	pos_y;
	int	is_reachable;
}	t_coll;

typedef struct s_imgs
{
	void	*wall;
	void	*empty;
	void	*enemy;
	void	*item;
	void	*exit;
	void	*door_open;
}	t_imgs;

typedef struct s_level
{
	int	height;
	int	width;

}	t_level;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**level;
	t_player	player;
	t_imgs		imgs;
	t_level		level_size;
	t_coll		*collectibles;
	int			cur_frame;
	int			player_frame;
	int			moves;
	int			items;
	int			remaining_items;
	int			door_pos_x;
	int			door_pos_y;
	int			is_resolvable;
	int			errors;
	int			can_move;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

int		quit_game(t_data *data);
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_data *data);
int		render(t_data *data);
int		render_rect(t_data *data, t_rect rect);
int		check_collision(t_data *data, int x, int y);
int		parse_map(t_data *data);
int		animate_player(t_data *data);
int		render_entities(t_data *data);
int		check_walls(char **level);
int		check_doubles(char **level);
int		check_items(char **level);
int		death_anim(t_data *data);
char	**ft_split(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
void	read_level(char *path, t_data *data);
void	init_player(t_data *data);
void	load_images(t_data *data);
void	check_access(t_data *data, int x, int y, int is_item);
void	add_move(t_data *data);
void	start_death_anim(t_data *data);
void	set_items_positions(t_data *data);
void	check_collectibles(t_data *data);
void	free_level(t_data *data);
void	check_errors(t_data *data, char *level);

#endif
