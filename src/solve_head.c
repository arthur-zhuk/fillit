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
** > how to access the information in a struct:
**		> mc->x = whatever the x is 
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
	int		i;
	int		size;

	i = 0;
	size = 5;
	while (mc -> y + i < 4 && gc -> y + i < size)
	{
		printf("in while i: %d\n", i);
		if (s_compare(m, g, mc, gc))
			i++;
		else
			iterate_grid_coord(mc, size);
	}

	return (1);
}

int		s_compare(char **m, char **g, t_coord *mc, t_coord *gc)
{
	int		i;
	int		pass;

	pass = 1;		
	i = 0;
	// while g and m are both valid
	// if m == '#' and g == '.'
	// then g == '#'

	while (m[mc -> y][mc -> x + i] != '\0' && g[gc -> y][gc -> x + i] != '\0')
	{
		printf("mino [%d, %d] = %c\n", mc -> y, mc -> x + i, m[mc -> y][mc -> x + i]);
		printf("grid [%d, %d] = %c\n\n", gc -> y, gc -> x + i, g[gc -> y][gc -> x + i]);
		if (m[mc -> y][mc -> x + i] == '#' && g[gc -> y][gc -> x + i] != '.')
			return (1);
		i++;
	}

	return (1);
}

int		iterate_grid_coord(t_coord *gc, int size)
{
	if (gc -> x < size - 1)
	{
		gc -> x ++;
		return (1);
	}
	else if (gc -> x == size - 1 && gc -> y != size - 1)
	{
		gc -> x = 0;
		gc -> y ++;
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


