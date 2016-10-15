NAME = fillit

FLAG = -Wall -Werror -Wextra #-fsanitize=address -ggdb
LFLAGS = -L. -lft

SRC = 	input_head.c 		\
		input_checks.c 		\
		input_helpers.c 	\
		main.c 				\
		solve_recursive.c	\
		solve_helpers.c		\
		solve_helpers_two.c \
		solve_placement.c 	\
		print_helpers.c		\

OBJ = $(SRC:.c=.o)
SRCDIR = src/
INCLUDE = include/

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(addprefix $(SRCDIR),$(SRC)) -I $(INCLUDE)
	gcc -o $(NAME) $(OBJ) $(LFLAGS) 

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
