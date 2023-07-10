# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpothin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 17:04:57 by cpothin           #+#    #+#              #
#    Updated: 2023/03/22 17:05:01 by cpothin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bsq
NAME_DEBUG	=	bsq_debug

CC			=	gcc
RM			= 	rm -rf

CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address

# **************************************************************************** #
#	MAKEFILE	#

MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	SRCS	#

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./includes/

SRCS =		$(wildcard $(SRCSPATH)*.c) $(wildcard $(SRCSPATH)**/*.c)
SRCSNAME =	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME =	$(SRCSNAME:.c=.o)
OBJS =		$(addprefix $(OBJSPATH), $(OBJSNAME))

# *************************************************************************** #

define	progress_bar
	@i=0
	@while [[ $$i -le $(words $(SRCS)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	@printf "$(B)]\r[$(GRE)"
endef

# *************************************************************************** #
#	RULES	#

all:		launch $(NAME)
	@printf "\n$(B)$(MAG)$(NAME) compiled$(D)\n"

launch:
	$(call progress_bar)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@printf "█"

debug:
	@make CFLAGS+=-DDEBUG=1 NAME=$(NAME_DEBUG)

#test:
#	@make 

clean:
	@$(RM) $(OBJSPATH)
	@echo "$(B)Cleared$(D)"


fclean:		clean
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAME) $(NAME_DEBUG)

re:			fclean all

.PHONY: all clean fclean re launch debug test
