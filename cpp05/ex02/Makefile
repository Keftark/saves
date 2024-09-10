# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <cpothin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 14:07:58 by cpothin           #+#    #+#              #
#    Updated: 2024/01/25 15:58:00 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

$(NAME):
		$(CC) $(CFLAGS) Colors.cpp main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re