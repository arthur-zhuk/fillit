NAME = fillit

FLAG = -Wall -Werror -Wextra -fsanitize=address -ggdb

SRC = 	src/input_head.c 		\
		src/input_checks.c 		\
		src/input_helpers.c 	\
		src/main.c 				\
		src/solve_recursive.c	\
		src/solve_helpers.c		\
		src/solve_helpers_two.c \
		src/solve_placement.c 	\
		src/print_helpers.c		\

OBJ = $(SRC:.c=.o)
INCLUDES = -I include/fillit.h include/libft.h
LFLAGS = -L. -lft

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC) $(INCLUDES) $(LFLAGS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
