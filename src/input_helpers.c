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
	// printf("i: %d\n", i);
	i++;

	if (i % 21 != 0)
		return (0);
	return (i / 21);
}

int		shape_check(char *z, int indx, int prev, int ans)
{
	if (is_square(z, indx))
		return (4);

	// top
	if (indx - 4 >= 0 && z[indx - 4] == '#' && indx - 4 != prev)
	{
		// printf("top, index: %d, ans: %d\n", indx, ans);
		ans = shape_check(z, indx - 4, indx, ans);
	}


	// right
	if (indx % 4 != 3 && z[indx + 1] == '#' && indx + 1 != prev)
	{
		// printf("right, index: %d, ans: %d\n", indx, ans);
		ans = shape_check(z, indx + 1, indx, ans);
	}


	// bottom
	if (indx + 4 < 16 && z[indx + 4] == '#' && indx + 4 != prev)
	{
		// printf("bottom, index: %d, ans: %d\n", indx, ans);
		ans = shape_check(z, indx + 4, indx, ans);
	}


	// left
	if (indx % 4 != 0 && z[indx - 1] == '#' && indx - 1 != prev)
	{
		// printf("left, index: %d, ans: %d\n", indx, ans);
		ans = shape_check(z, indx - 1, indx, ans);
	}

	// printf("\n\n-----fail>>>>>\n");
	// printf("ans: %d, index: %d, prev: %d\n", ans, indx, prev);
	// printf("%d, %c, %d\n", indx + 4, z[indx + 4], indx + 4 != prev);
	// printf("^^^^^^^fail-----\n\n\n");
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
	{
		// printf("is square\n\n");
		return (1);
	}
	return (0);
}
