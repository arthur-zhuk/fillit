#include "../include/libft.h"
#include "../include/fillit.h"

int		min_x_point(char **mino)
{
	int		i;
	int		j;
	int		x;

	x = 4;
	i = 0;
	j = 0;
	while (mino[i])
	{
		j = 0;
		while (mino[i][j])
		{
			if (mino[i][j] == '#' && j < x)
				x = j;
			j++;
		}
		i++;
	}
	return (x);
}

int		min_y_point(char **mino)
{
	int		i;
	int		j;
	int		y;

	y = 4;
	i = 0;
	j = 0;
	while (mino[i])
	{
		j = 0;
		while (mino[i][j])
		{
			if (mino[i][j] == '#' && i < y)
				y = i;
			j++;
		}
		i++;
	}
	return (y);
}

char	**make_two_d(int x, int y, char *data)
{
	int		i;
	int		j;
	int		k;
	char	**grid;

	i = 0;
	j = 0;
	k = 0;
	grid = (char **)malloc(sizeof(char *) * (x + 1));
	while (i < x)
	{
		grid[i] = (char *)malloc(sizeof(char) * (y + 1));
		j = 0;
		while (j < y)
		{
			grid[i][j] = data[k];
			j++;
			k++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = 0;
	return (grid);
}

char	**h_make_grid(int size)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	j = 0;
	grid = (char **)malloc(sizeof(char *) * (size * size + 1));
	while (i < size)
	{
		grid[i] = (char *)malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = 0;
	return (grid);
}

char	**make_mino(char *z)
{
	int		i;
	int		j;
	int		k;
	char	**mino;

	i = 0;
	j = 0;
	k = 0;
	mino = (char **)malloc(sizeof(char *) * (4 + 1));
	while (i < 4)
	{
		mino[i] = (char *)malloc(sizeof(char) * (4 + 1));
		j = 0;
		while (j < 4)
		{
			mino[i][j] = z[k];
			j++;
			k++;
		}
		mino[i][j] = '\0';
		i++;
	}
	mino[i] = 0;
	return (mino);
}


int		h_iterate_grid_coord(t_coord *coords, int size)
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














/*
int		open_space(char **grid, int start, int size)
{
	int		i;
	int		j;

	if (start == 0)
	{
		i = 0; //start / size;
		j = 0; //start % size;
	} else
	{
			i = 0; //start / size;
		j = 0; //start % size;

	}
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
			{
				return (size * i + j);
			}
			j++;
		}
		i++;
	}
	return (0);
}
*/