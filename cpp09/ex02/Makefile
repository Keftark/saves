NAME = PMergeMe

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
RM = rm -f

$(NAME):
		$(CC) $(CFLAGS) main.cpp PMergeMe.cpp Colors.cpp -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re