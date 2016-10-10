#include "./include/libft.h"
#include "./include/fillit.h"
#include <fcntl.h>

char	*read_data(char *av);

int		line_check(char *av)
{
	char	*ret;
	int		i;

	i = 0;
	ret = read_data(av);
	printf("%s\n", ret);
	while (*ret)
	{
		if (*ret == '\n' && *(ret + 1) == '\n')
		{
			i++;
		}
		ret++;
	}
	return (i);
}

int		line_cnt(char *av)
{
	char	*ret;
	int		i;

	i = 0;
	ret = read_data(av);

	while (*ret)
	{
		if (*ret != '\n' && (*ret == '#' || *ret == '.'))
		{
			i++;
			printf("%d", i);
		}
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

int		valid_row(char *av)
{
	char	*ret;
	int		i;

	ret = read_data(av);
	i = 0;
	while (*ret != '\n')
	{
		if (*ret == '#' || *ret == '.')
		{
			i++;
			printf("%d", i);
		}
		ret++;
	}
}
