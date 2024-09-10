# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 14:07:58 by cpothin           #+#    #+#              #
#    Updated: 2023/11/27 09:51:20 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ZombieRef

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

$(NAME):
		$(CC) $(CFLAGS) main.cpp -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
