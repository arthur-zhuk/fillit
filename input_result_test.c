
#include "./include/libft.h"
#include "./include/fillit.h"
#include <fcntl.h>

char	*read_data(char *av);

char	*line_check(char *av)
{
	char	*ret;
	int		i;

	i = 1;
	ret = read_data(av);
	printf("%s\n is my function working?", ret);
	while (*ret)
	{
		if (*ret == '\n')
		{
			printf("%d", i);
			i++;
		}
		ret++;
	}

	return (ret);
}
