#include "../include/libft.h"
#include "../include/fillit.h"


char	*solve_entrance(char *z)
{
	char	**mino;
	char	**grid;

	grid = make_two_d(5, 5, ".........................");
	mino = make_two_d(4, 4, z);
	ft_puttab(mino);
	ft_puttab(grid);
	printf("min x: %d\n", min_x_point(mino));
	printf("min y: %d\n", min_y_point(mino));
	printf("open space: %d\n", open_space(grid, 0, 0));

	return (0);
}

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