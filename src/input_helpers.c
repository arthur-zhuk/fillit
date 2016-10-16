#include "../include/libft.h"
#include "../include/fillit.h"

int		find_hash(char *z)
{
	int		i;

	i = 0;
	while ((z[i] != '#') && (z[i] != '\0'))
		i++;
	return (i);
}

int		tetrimino_count(char *z)
{
	int		i;

	i = 0;
	while (z[i] != '\0')
		i++;
	i++;

	if (i % 21 != 0)
		return (0);
	return (i / 21);
}

int		shape_check(char *z, int indx, int prev, int ans)
{
	if (is_square(z, indx))
		return (4);
	if (indx - 4 >= 0 && z[indx - 4] == '#' && indx - 4 != prev)
	{
		ans = shape_check(z, indx - 4, indx, ans);
	}
	if (indx % 4 != 3 && z[indx + 1] == '#' && indx + 1 != prev)
	{
		ans = shape_check(z, indx + 1, indx, ans);
	}
	if (indx + 4 < 16 && z[indx + 4] == '#' && indx + 4 != prev)
	{
		ans = shape_check(z, indx + 4, indx, ans);
	}
	if (indx % 4 != 0 && z[indx - 1] == '#' && indx - 1 != prev)
	{
		ans = shape_check(z, indx - 1, indx, ans);
	}
	return (ans + 1);
}

int is_square(char *z, int indx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (z[i])
	{
		if (z[i] == '#')
			j++;
		i++;
	}
	if (indx % 4 == 3 && indx / 4 == 3)
		return (0);
	if (z[indx + 1] == '#' && z[indx + 4] == '#' && z[indx + 5] == '#')
		return (1);
	return (0);
}
