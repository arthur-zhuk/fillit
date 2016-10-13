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

	grid = h_make_grid(5);
	grid[0][0] = '*';
	grid[0][2] = '*';
	grid[0][4] = '*';
	// grid[0][1] = '*';
	printf("\nstart grid: \n");
	print_mino(grid);

	gc = (t_coord *)malloc(sizeof(t_coord));
	gc -> y = 0;
	gc -> x = 0;

	mino = make_mino(z);
	printf("\nstart mino\n");
	print_mino(mino);

	mc = (t_coord *)malloc(sizeof(t_coord));
	mc -> y = min_y_point(mino);
	mc -> x = min_x_point(mino);

	// start the compare function
	s_compare_control(mino, grid, mc, gc);


	print_mino(mino);
	print_mino(grid);
	return (0);
}

int		s_compare_control(char **m, char **g, t_coord *mc, t_coord *gc)
{
	// iterate through lines
	// if this function should return 1 unless the map is full
	// if the map is full then we need to recurse
	int		keep_going;

	keep_going = 1;

	while (keep_going)
	{
			if (s_compare(m, g, mc, gc))
			{
				printf("successful placement\n");
				keep_going = 0;
			}
			else
			{
				printf("failed compare\n\n");
				keep_going = h_iterate_grid_coord(gc, 5);
			}
	}
	return (1);
}

// Optimization could be gained by adding a stop condition for when the bottom of the mino goes
// off the bottom of the grid.
int		s_compare(char **m, char **g, t_coord *mc, t_coord *gc)
{
	// takes in a mino and coordinates on the map
	// returns 1 if there is no conflict with that placement of the mino
	int		i;
	int		j;
	int		k;
	// counts number of #'s that werre compared.  If at the end the counter
	// does not equal 4, that means that one of the mino hash's was not on the grid
	int		size;

	size = 5;
	i = 0;
	j = 0;
	k = 0;
	while (mc -> y + k < 4 && gc -> y + k < size)
	{
		while (m[mc -> y + k][mc -> x + i] != '\0' && g[gc -> y + k][gc -> x + i] != '\0')
		{
			printf("grid [%d, %d] = %c\n", gc -> y + k, gc -> x + i, g[gc -> y + k][gc -> x + i]);
			printf("mino [%d, %d] = %c\n\n", mc -> y + k, mc -> x + i, m[mc -> y + k][mc -> x + i]);
			if (m[mc -> y + k][mc -> x + i] != '.' && g[gc -> y + k][gc -> x + i] != '.')
				return (0);
			if (m[mc -> y + k][mc -> x + i] != '.')
				j++;
			i++;
		}
		i = 0;
		k++;
		// printf("--new line--\n");
		// printf("grid y: %d, x: %d\n\n", gc -> y, gc -> x + i);
	}
	if (j == 4)
	{
		return (1);
	}
	printf(">>>> j: %d\n", j);
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


