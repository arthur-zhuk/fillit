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