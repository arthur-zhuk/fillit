#include "../include/fillit.h"
#include "../include/libft.h"
#include "../include/solve.h"


char	*controller(char *z)
{
	MAP = ".........................";
	map_solver();
}

char	*map_solver(char *z)
{
	int		i;

	i = 0;
	while (z[i])
	{
		if ((i + 1) % 16 == 0)
		{

			place_piece(ft_strdup_n(&z[i], 15));
		}
		i++;
	}
}

int		*place_piece(char *z)
{
	char	*dumbpiece;
	int		i;

	i = 0;
	printf("place_piece function");
	//find_open_space(map, z);
	}
	free(z);
	return (0);
}

int		find_open_space(char *map, char *z)
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '#')
			return(i);
		i++;
	}
}

int		fits(char *map, int x, char *piece)
{
	int		i;

	i = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] != map[x])
			i++;
		else
			return (0);
	}
}

/*
  0  1  2  3  4
  .  .  .  .  .
  5  6  7  8  9
  .  .  .  .  .
  10 11 12 13 14
  .  .  .  .  .
  15 16 17 18 19
  .  .  .  .  .
  20 21 22 23 24
  .  .  .  .  .

  */
