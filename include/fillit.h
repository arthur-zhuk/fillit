
#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h> // printf
#include <fcntl.h> // open
#include <errno.h> // errno

char	*read_data(char *av);
char	*input_data(char *av);
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
int		dot_hash_check(char *z);
int		input_error(int	*check);
char	*hash_to_letter(char *z);
void	prnt_str2grid(char *z);

/*
** solve
*/

char	*controller(char *z);
char	*map_solver(char *z, char *map);
int		*place_piece(char *z, int x);
int		find_open_space(char *map);
int		fits(char *map, char *mino, int hash_index, int space_index);
char	*up_left(char *z);
void	ft_putstr_sqr(char *str, int w);
int		h_min(char *mino);


char	*ft_strdup_n(const char *src, int n);





int		line_cnt(char *av);
int		line_check(char *av);

#endif
