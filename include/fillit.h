
#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h> // printf
#include <fcntl.h> // open
#include <errno.h> // errno
#include <stdlib.h>

typedef struct 		s_coord
{
	int 			y;
	int				x;
	int				size;
}					t_coord;

char	*read_data(char *av);
char	*input_data(char *av);
int		check_grid_lines(char *input);
int		last_char_nl(char *input);
int		symbol_check(char *x);
int		tetrimino_count(char *z);
int		nl_check(char *z);
void	error_check(void);
int		shape_check(char *z, int indx, int prev, int ans);
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

/*
** input index
*/

char	*rm_nl(char *z, int num_mino);



/*
** input helpers
*/

int is_square(char *z, int indx);

/*
** 2d array solve
*/

int		ft_make_map(char **piece_list);
char	**make_two_d(int x, int y, char *data);
int		solve_entrance(char **grid, char **z, int index);
int		open_space(char **grid, int start, int size);
int		s_compare(char **m, char **g, t_coord *mc, t_coord *gc);
int		s_compare_control(char **m, char **g, t_coord *mc, t_coord *gc);
int		s_place_piece(char **m, char **g, t_coord *mc, t_coord *gc);


/*
** Solve Helpers
*/

int		min_x_point(char **mino);
int		min_y_point(char **mino);
int		h_new_line(t_coord *coords, int size);
char	**h_make_grid(int size);
char	**make_mino(char *z);
int		h_iterate_grid_coord(t_coord *gc, int size);

/*
** Recursive
*/

int		ft_make_map(char **piece_list);
int		ft_recursive(char **piece_list, char **grid);
char	**ft_new_piece_list(char **piece_list, int piece_index);
size_t	ft_strlen_dub(char **str);
void	ft_unplace_piece(char **grid, char *piece);

/*
** Print helpers
*/

void	print_mino(char **mino);



#endif
