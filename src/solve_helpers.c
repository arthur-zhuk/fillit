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
