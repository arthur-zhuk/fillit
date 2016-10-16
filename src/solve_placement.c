#include "../include/libft.h"
#include "../include/fillit.h"

int		solve_entrance(char **grid, char **z, t_coord *gc)
{
	char	**mino;
	t_coord	*mc;

	mino = make_mino(z[0]);
	mc = (t_coord *)malloc(sizeof(t_coord));
	mc -> y = min_y_point(mino);
	mc -> x = min_x_point(mino);
	mc -> size = 4;
	if (s_compare_control(mino, grid, mc, gc))
		return (1);
	else
		return (0);
}

int		s_compare_control(char **m, char **g, t_coord *mc, t_coord *gc)
{
	int		keep_going;

	keep_going = 1;
	while (keep_going)
	{
			if (s_compare(m, g, mc, gc))
			{
				s_place_piece(m, g, mc, gc);
				return (1);
			}
			else
				keep_going = h_iterate_grid_coord(gc);
	}
	return (0);
}

int		s_place_piece(char **m, char **g, t_coord *mc, t_coord *gc)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (mc -> y + k < mc -> size && gc -> y + k < gc -> size)
	{
		while (m[mc -> y + k][mc -> x + i] != '\0' && g[gc -> y + k][gc -> x + i] != '\0')
		{
			if (m[mc -> y + k][mc -> x + i] != '.')
			{
				g[gc -> y + k][gc -> x + i] = m[mc -> y + k][mc -> x + i];
			}
			i++;
		}
		i = 0;
		k++;
	}
	return (0);
}

int		s_compare(char **m, char **g, t_coord *mc, t_coord *gc)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (mc -> y + k < mc -> size && gc -> y + k < gc -> size)
	{
		while (m[mc -> y + k][mc -> x + i] != '\0' && g[gc -> y + k][gc -> x + i] != '\0')
		{
			if (m[mc -> y + k][mc -> x + i] != '.' && g[gc -> y + k][gc -> x + i] != '.')
				return (0);
			if (m[mc -> y + k][mc -> x + i] != '.')
				j++;
			i++;
		}
		i = 0;
		k++;
	}
	if (j == 4)
	{
		return (1);
	}
	return (0);
}

int		h_new_line(t_coord *coords, int size)
{
	if (coords -> y != size - 1)
	{
		coords -> y++;
		return (1);
	}
	return (0);
}
