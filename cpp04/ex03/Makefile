# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 14:07:58 by cpothin           #+#    #+#              #
#    Updated: 2023/12/16 09:12:46 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AMateria

CC = c++
CFLAGS = -Wall -Wextra -Werror -g3 -std=c++98
RM = rm -f

$(NAME):
		$(CC) $(CFLAGS) Colors.cpp main.cpp MateriaSource.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
