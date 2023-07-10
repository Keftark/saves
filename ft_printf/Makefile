# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 14:06:23 by cpothin           #+#    #+#              #
#    Updated: 2023/04/17 14:06:25 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MAKEFLAGS += --silent

CC = gcc
INCLUDE = include
CFLAGS = -Wall -Wextra -Werror -I
LIBFT = libft
AR = ar rcs
RM = rm -rf

FILES = ft_printf \
	ft_print_common \
	ft_print_hex \
	ft_print_unsigned \
	ft_print_ptr \

SRCS_DIR = src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJF = .cache_exists
		
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\033[0;93m"
	@echo " ---------------------------------- "
	@echo "[                                  ]"
	@echo " ---------------------------------- "
	@echo "\n             Compiling!\033[0;93m\n\n\033[1A\033[1A\033[1A\033[1A"
	@echo -n "\033[1A\033[1A\r["
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "\033[0m\033[1A\033[32m\r ---------------------------------- "
	@echo "[\033[42m                                  \033[0m\033[32m]"
	@echo " ---------------------------------- "
	@echo "\n             Compiled!  \033[0;39m\n"

all: $(NAME)

newline:
	@echo "\n"

clean:
	@$(RM) $(OBJS_DIR)
	@make clean -C $(LIBFT)
	@echo "\033[0;34mC\033[0;35ml\033[0;31me\033[0;33ma\033[0;32mn\033[0;36me\033[0;34md\033[0m"

fclean:
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a
	@$(MAKE) --no-print-directory clean
	@echo " \033[0;31me\033[0;33mv\033[0;32me\033[0;36mr\033[0;34my\033[0;35mt\033[0;31mh\033[0;33mi\033[0;32mn\033[0;36mg\033[0m"

re: newline fclean all

.PHONY: all clean fclean re newline
