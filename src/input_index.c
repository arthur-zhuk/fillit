#include "../include/fillit.h"
#include "../include/libft.h"

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

	if (i % 21 == 0)
		return (0);
	return (i + 1 / 21);
}

int		nl_check(char *z, int num_minos)
{
	int		i;

	i = 0;
	while (	z[i] != '\0' )
	{
		if ((i - (i / 21)) % 5 == 4 && z[i] != '\n')
		{
			printf("im in 1");
			return (0);
		}
		if ((i - (i / 21)) % 5 < 4 && (z[i] != '#' && z[i] != '.'))
		{
			printf("%d im in 2. I'm a:  %c\n", i, z[i]);
			return (0);
		}
		if ((i % 21) == 0 && z[i - 1] != '\n' && i != 0)
		{
			printf("i: %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*rm_nl(char *z)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * ft_strlen(z));
	while (z[i] != '\0')
	{
		if (z[i] != '\n')
		{
			ret[j] = z[i];
			j++;
		}
		i++;
	}
	return (ret);
}

int		pre_shape_check(char *z)
{
	char	*inpt;
	int		i;

	i = 0;
	inpt = ft_strdup_n(z, 16);
	while (z[i] != '\0')
	{
		if (i % 16 == 0)
		{
			if (shape_check(inpt, find_hash(z), 100, 0) != 4)
				return (0);
		}
		ft_bzero(inpt, 16);
	}
	free(inpt);
	return (1);
}

int		shape_check(char *z, int indx, int prev, int ans)
{
	// top
	if (indx - 4 >= 0 && z[indx - 4] == '#' && indx - 4 != prev)
	{
		printf("top, index: %d, ans: %d\n", indx, ans);
		ans = shape_check(z, indx - 4, indx, ans);
	}


	// right
	if (indx % 4 != 3 && z[indx + 1] == '#' && indx + 1 != prev)
	{
		printf("right, index: %d, ans: %d\n", indx, ans);
		ans = shape_check(z, indx + 1, indx, ans);
	}


	// bottom
	if (indx + 4 < 16 && z[indx + 4] == '#' && indx + 4 != prev)
	{
		printf("bottom, index: %d, ans: %d\n", indx, ans);
		ans = shape_check(z, indx + 4, indx, ans);
	}


	// left
	if (indx % 4 != 0 && z[indx - 1] == '#' && indx - 1 != prev)
	{
		printf("left, index: %d, ans: %d\n", indx, ans);
		ans = shape_check(z, indx - 1, indx, ans);
	}

	printf("\n\n-----fail>>>>>\n");
	printf("ans: %d, index: %d, prev: %d\n", ans, indx, prev);
	printf("%d, %c, %d\n", indx + 4, z[indx + 4], indx + 4 != prev);
	printf("^^^^^^^fail-----\n\n\n");
	return (ans + 1);


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

*/


char	*ft_strdup_n(const char *src, int n)
{
	int		i;
	char	*str;

	str = (char*)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		find_hash(char *z)
{
	int		i;

	i = 0;
	while (z[i] != '#')
		i++;
	return (i - 1);
}



