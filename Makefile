NAME = libft.a solve.a fillit.a
MAIN = fillit

FLAG = -c -Wall -Werror -Wextra

SRC = input_result_test.c src/input_checks.c src/input_helpers.c src/input_index.c src/main.c src/read_data.c
OBJ = $(SRC:.c=.o)
INCLUDES = include/fillit.h include/libft.h include/solve.h
LFLAGS = -L . -lft

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC) -I $(INCLUDES) $(LFLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
