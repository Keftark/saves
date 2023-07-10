# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 08:29:13 by cpothin           #+#    #+#              #
#    Updated: 2023/06/09 08:29:14 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	client
NAME_SERVER	=	server

MAKEFLAGS += --silent
AR = ar rcs
RM = rm -rf
CC =	cc
INCLUDE = -I include
CFLAGS	= -Wextra -Werror -Wall -g3

FILES =	client \
		utils \
		ft_atoi

FILES_SERVER =	server \
		utils \
		ft_atoi \
		ft_bzero
	
SRCS_DIR = src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_SERVER = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_SERVER)))

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_SERVER = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_SERVER)))

all:	${NAME} ${NAME_SERVER}

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): ${OBJS}
		$(CC) ${OBJS} -o $(NAME)
		
$(NAME_SERVER): ${OBJS_SERVER}
		$(CC) ${OBJS_SERVER} -o $(NAME_SERVER)

clean:
	@$(RM) $(OBJS_DIR)


fclean:
	@$(RM) $(NAME) $(NAME_SERVER)
	@$(MAKE) --no-print-directory clean
		
re:	fclean all

.PHONY: all clean fclean re
