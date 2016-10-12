#include "../include/libft.h"
#include "../include/fillit.h"

/*

** > struct is for holding coordinate
** > there is a struct for grid and mino (m and c)
** > the structs hold the coordinates for the place we want
**		to compare in both arrays
** > so far 2 structs one for our location in mino and one for grid
** > mino, grid, mino struct (mc), grid struct (gc) are passed to s_place
** > s_place (for the moment) just compares 1 line
** > if there is a conflict it returns 0
** > it does not place the piece!
** > it simply checks if there is room for the piece
** > if there is room, then we will need to place the piece
** > haven't gotten to that yet
**
** > how to access the information in a struct pointer:
**		> mc->x 
**
**
**
**
*/

char	*solve_entrance(char *z)
{
	char	**mino;
	char	**grid;
	t_coord	*gc;
	t_coord	*mc;

	grid = make_two_d(5, 5, ".........................");
	mino = make_two_d(4, 4, z);
	ft_puttab(mino);
	ft_puttab(grid);
	printf("min x: %d\n", min_x_point(mino));
	printf("min y: %d\n", min_y_point(mino));
	//printf("open space: %d\n", open_space(grid, 0, 0));

	mc = (t_coord *)malloc(sizeof(t_coord));
	gc = (t_coord *)malloc(sizeof(t_coord));
	mc -> y = min_y_point(mino);
	mc -> x = min_x_point(mino);
	gc -> y = 0;
	gc -> x = 0;
	printf("s_compare_control result: %d", s_compare_control(mino, grid, mc, gc));
	ft_puttab(mino);
	ft_puttab(grid);
	return (0);
}

int		s_compare_control(char **m, char **g, t_coord *mc, t_coord *gc)
{
	// iterate through lines
	// if this function should return 1 unless the map is full
	// if the map is full then we need to recurse




		printf("in while mc: %d, gc: %d\n", mc -> y, gc -> y);
		if (s_compare(m, g, mc, gc))
		{
			printf("successful placement\n");
		}
		// else if (!(iterate_grid_coord(mc, size)))
		// {
		// 	printf("grid full");
		// 	break;
		// }

	return (1);
}

int		s_compare(char **m, char **g, t_coord *mc, t_coord *gc)
{
	// takes in a mino and coordinates on the map
	// returns 1 if there is no conflict with that placement of the mino
	int		i;
	int		size;

	size = 5;
	i = 0;

	while (mc -> y < 4 && gc -> y < size)
	{
		while (m[mc -> y][mc -> x + i] != '\0' && g[gc -> y][gc -> x + i] != '\0')
		{
			printf("mino [%d, %d] = %c\n", mc -> y, mc -> x + i, m[mc -> y][mc -> x + i]);
			printf("grid [%d, %d] = %c\n\n", gc -> y, gc -> x + i, g[gc -> y][gc -> x + i]);
			if (m[mc -> y][mc -> x + i] != '.' && g[gc -> y][gc -> x + i] != '.')
				return (0);
			i++;
		}
		if(!(h_new_line(mc, 4)) || !(h_new_line(gc, size)))
			break;
		i = 0;
		printf("mino y: %d, x: %d\n", mc -> y, mc -> x + i);
		printf("grid y: %d, x: %d\n\n", gc -> y, gc -> x + i);
	}
	return (1);
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

int		iterate_grid_coord(t_coord *coords, int size)
{
	if (coords -> x < size - 1)
	{
		coords -> x++;
		return (1);
	}
	else if (coords -> x == size - 1 && coords -> y != size - 1)
	{
		coords -> x = 0;
		coords -> y++;
		return (1);
	}
	else
		return (0);
}












int		comp_x(t_coord *a, t_coord *b)
{
	if (a -> x == b -> x)
		return (1);
	return (0);
}






// if (m[mc -> y][mc -> x + i] == '#' && g[gc -> y][gc -> x + i] == '.')
/*
	Psudo code - ignore not helpful

	while increment through grid
		while iterate through rows
			while
				compare rows

		if increment = grid_size - 1
			iterate_line(gid coordinates)


	return (0);
}

*/


