/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 12:09:19 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/17 12:25:15 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_coord
{
	int				y;
	int				x;
	int				size;
}					t_coord;

/*
** Input Head
*/

char				**input_data(char *av);
char				*read_data(char *av);
void				graceful_exit(char *str);

/*
** Input Checks
*/

int					nl_check(char *z);
int					dot_hash_check(char *z);
char				*rm_nl(char *z, int num_mino);
int					pre_shape_check(char *z);
char				*hash_to_letter(char *z);

/*
** Input Helpers
*/

int					find_hash(char *z);
int					tetrimino_count(char *z);
int					shape_check(char *z, int indx, int prev, int ans);
int					is_square(char *z, int indx);

/*
** Solve Recursive
*/

int					ft_make_map(char **piece_list);
int					ft_recursive(char **piece_list, char **grid);
void				ft_unplace_piece(char **grid, char *piece);
char				**ft_new_piece_list(char **piece_list, int piece_index);
int					ft_strlen_dub(char **str);

/*
** Solve Placement
*/

int					solve_entrance(char **grid, char **z, t_coord *gc);
int					s_compare_control(char **m,
						char **g, t_coord *mc, t_coord *gc);
int					s_place_piece(char **m, char **g, t_coord *mc, t_coord *gc);
int					s_compare(char **m, char **g, t_coord *mc, t_coord *gc);
int					h_new_line(t_coord *coords, int size);

/*
** Solve Helpers
*/

int					min_x_point(char **mino);
int					min_y_point(char **mino);
char				**h_make_grid(int size);
char				**make_two_d(int x, int y, char *data);
char				**make_mino(char *z);

/*
** Solve Helpers Two
*/

int					h_iterate_grid_coord(t_coord *coords);
char				*ft_strdup_n(const char *src, int n);
int					ft_sqrt(int nb);

/*
** Print helpers
*/

void				print_mino(char **mino);
void				prnt_str_to_grid(char *z);

#endif
