
#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>

int		check_grid_lines(char *input);
int		last_char_nl(char *input);
int		symbol_check(char *x);
int		tetrimino_count(char *z);
int		nl_check(char *z, int num_minos);
void	error_check(void);
int		shape_check(char *z, int indx, int prev, int ans);
char	*rm_nl(char *s);
char	*ft_strdup_n(const char *src, int n);
int		find_hash(char *z);
int		pre_shape_check(char *z);


int 	line_check(char *av);

#endif
