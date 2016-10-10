
#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>

int		check_grid_lines(char *input);
int		last_char_nl(char *input);
int		symbol_check(char *x);
int		tetrimino_count(char *z);
int		nl_check(char *z, int num_minos);


int 	line_check(char *av);

#endif
