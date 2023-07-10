# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefil                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 15:58:06 by cpothin           #+#    #+#              #
#    Updated: 2023/05/27 15:58:28 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

MAKEFLAGS += --silent
LIBDIR = ./mlx
AR = ar rcs
RM = rm -rf
CC =	gcc
MLX = mlx
INCLUDE = include
CFLAGS	=	-Wall -Wextra -Werror -g3

FILES = so_long \
	inputs \
	rendering \
	utils \
	level \
	movements \
	ft_itoa \
	anims \
	check_errors \
	check_errors2 \
	quit_game
	
SRCS_DIR = src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -Iminilibx-linux mlx/libmlx_Linux.a -lXext -lX11 -lm -lz -c $< -o $@

$(NAME): ${OBJS}
		cd ./mlx && ./configure && $(MAKE)
		$(CC) ${OBJS} -Iminilibx-linux mlx/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME) 

#-L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
all:	${NAME}

clean:
	@$(RM) $(OBJS_DIR)


fclean:
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory clean
		
re:	fclean all

.PHONY: all clean fclean re
