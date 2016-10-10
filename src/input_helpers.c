#include "../include/libft.h"
#include "../include/fillit.h"

int		find_hash(char *z)
{
	int		i;

	i = 0;
	while (z[i] != '#')
		i++;
	return (i);
}

int		tetrimino_count(char *z)
{
	int		i;

	i = 0;
	while (z[i] != '\0')
	{
		i++;
	}
	printf("i: %d\n", i);
	i++;

	if (i % 21 != 0)
		return (0);
	return (i / 21);
}

int		shape_check(char *z, int indx, int prev, int ans)
{
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

void	prnt_str2grid(char *z)
{
	int		i;

	i = 0;
	while (z[i] != '\0')
	{
		printf("%c", z[i]);
		if (i % 4 == 3)
			printf("\n");
		i++;
	}
}

/*

0  1  2  3
.  #  .  .

4  5  6  7
#  #  #  .

8  9  10 11
.  .  .  .

12 13 14 15
.  .  .  .



0  1  2  3
.  .  .  .

4  5  6  7
.  .  #  #

8  9  10 11
.  #  #  .

12 13 14 15      
.  .  .  .




> pass in individual mino string, and coordinates of first hash
> find first hash
> function( first hash) : return ( 1 + funtion( next hash))
	
	> check top.  
		if found #, then recursively call function on that hash
	> check right
		if found #, then recursively call function on that hash
	> check bottom
		if found #, then recursively call function on that hash
	> check left
		if found #, then recursively call function on that hash

	> if none return 0

shape = shape_check("......##.##.....", 6, 100, 0);
	shape = shape_check(".#..###.........", 1, 100, 0);
	shape = shape_check(".....###.#......", 5, 100, 0);
	shape = shape_check("#...#...#...#...", 0, 100, 0);
	shape = shape_check(".....##...#...#.", 5, 100, 0);
	int		shape;
	shape = shape_check("......##..#...#.", 6, 100, 0);
	printf("shape check: %d", shape);

*/
