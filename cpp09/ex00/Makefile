# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 14:07:58 by cpothin           #+#    #+#              #
#    Updated: 2024/02/20 09:59:39 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
RM = rm -f

$(NAME):
		$(CC) $(CFLAGS) Colors.cpp main.cpp BitcoinExchange.cpp -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re