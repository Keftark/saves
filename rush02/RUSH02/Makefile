# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 15:45:39 by cpothin           #+#    #+#              #
#    Updated: 2023/03/19 17:00:18 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
MAIN_DICTIONARY = numbers.dict

$(NAME):
	@gcc -Wall -Wextra -Werror main.c -o $(NAME) -fsanitize=address

clean:
	@find . -name $(NAME) -delete

fclean: clean
	@find data -name *.dict -not -name $(MAIN_DICTIONARY) -delete
