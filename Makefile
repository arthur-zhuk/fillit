NAME = fillit

FLAG = -Wall -Werror -Wextra

SRC = 	input_result_test.c 	\
		src/input_checks.c 		\
		src/input_helpers.c 	\
		src/input_index.c 		\
		src/main.c 				\
		src/read_data.c 		\
		src/solve.c				\
		src/solve_head.c		\
		src/solve_helpers.c		\
		src/solve_recursive.c	\
		src/print_helpers.c		\

OBJ = $(SRC:.c=.o)
INCLUDES = -I include/fillit.h include/libft.h include/solve.h
LFLAGS = -L. -lft

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	gcc $(SRC) $(INCLUDES) $(LFLAGS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
