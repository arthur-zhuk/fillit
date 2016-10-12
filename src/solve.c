#include "../include/fillit.h"
#include "../include/libft.h"
#include "../include/solve.h"

/*
** For reference:
** i = index of mino = mino[i]
** n = index of MAP = MAP[n]
** z = mino string
** mino = individual tetrimino
** map = solution
*/



char	*controller(char *z)
{
	char	*map;
	map = (char *)malloc(sizeof(char) * 26);
	ft_strcpy(map, ".........................");
	printf("map: %s\n", map);
	printf("z: %s\n", z);
	map_solver(z , map);
	return (0);
}

/*
** map_solver takes pieces off of the mino string (z)
** and passes individual minos to fits
*/
char	*map_solver(char *z, char *map)
{
	int		i;
	char	*mino;

	i = 0;

	// while (z[i])
	// {
	// 	if (i % 16 == 0)
	// 	{
	// 		printf("z: %s\n", z);

	// 		printf("map_solver while i: %d\n", i);
	// 		//printf("z: %s\n", z + i); // Why does this not work!!!
			mino = ft_strdup_n((z + i), 16);
	// 		printf("map_solver mino: %s\n", mino);
			fits(map, mino, find_hash(mino), find_open_space(map));
	// 	}
	// 	i++;
	// }
	return (0);
}

int		find_open_space(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '#')
			return(i);
		i++;
	}
	return (0);
}

int		fits(char *map, char *mino, int hash_index, int space_index)
{
	printf("fits hash_index: %d, space_index: %d\n", hash_index, space_index);
	

	int		i;
	int		n;
	int		h_off;
	int		v_off;
	int		offset;
	int		map_size;

	map_size = 5;
	i = 0;
	i = hash_index;
	v_off = -1 * (hash_index / 4) * 4;
	h_off = -1 * h_min(mino); 
	printf("hmin: %d, hash_index: %d, v_off: %d, h_off: %d\n",h_min(mino), hash_index, v_off, h_off);
	offset = v_off + h_off;
	printf("offset = %d\n", offset);



	n = 0;
	while (mino[i + offset] != '\0')
	{

		if (mino[i] == '#')
		{
			n = i + space_index + (i / 4) * (map_size - 4);
			printf("i: %d, n: %d\n", i, n);
			map[n] = mino[i];
		}
		i++;
	}
	//ft_putstr_sqr(map, 5);
	return (0);
}

int		h_min(char *mino)
{
	int		min;
	int		i;

	i = 0;
	min = 4;
	while (mino[i] != '\0')
	{
		if (mino[i] == '#' && i % 4 < min)
			min = i % 4;
		i++;
	}
	return (min);
}


git commit --amend --reset-author








































char	*ft_strdup_n(const char *src, int n)
{
	int		i;
	char	*str;
	str = (char*)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_putstr_sqr(char *str, int w)
{
	int		i;

	i = 0;
	while (i < (w * w) && str[i] != '\0')
	{
		if (i % w == 0)
			ft_putchar('\n');
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}














/*
char	*up_left(char *z)
{
	int		*d;
	int		i;

	i = 0;
	d = {0, 0, 0, 0};
	while (z[i] != '\0')
	{
		if ()
	}

}
*/













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
