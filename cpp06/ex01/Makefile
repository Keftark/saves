# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 14:07:58 by cpothin           #+#    #+#              #
#    Updated: 2024/01/30 09:44:50 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

$(NAME):
		$(CC) $(CFLAGS) Colors.cpp main.cpp Serializer.cpp -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re