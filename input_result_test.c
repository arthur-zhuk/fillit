#include "./include/libft.h"
#include "./include/fillit.h"
#include <fcntl.h>

char	*read_data(char *av);

int		line_check(char *av)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	ret = read_data(av);
	j = tetrimino_count(ret);

	printf("%s\n", ret);
	while (*ret)
	{
		if (*ret == '\n' && *(ret + 1) == '\n')
		{
			i++;
		}
		ret++;
	}
	if (i+1 != j)
	{
		printf("%s %d %s %d \n", "double n's", i, "tetris", j);
		return (0);
	}
	return (1);
}

int		line_cnt(char *av)
{
	char	*ret;
	int		i;

	i = 0;
	ret = read_data(av);

	while (*ret)
	{
		if (*ret == '\n' && *(ret - 1) == '\n')
		{
			break;
		}
		i = 0;
		ret++;
	}
	if (i != 16)
			return (0);
	return (1);
}
