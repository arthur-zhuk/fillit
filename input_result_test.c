
#include "./include/libft.h"
#include "./include/fillit.h"
#include <fcntl.h>

char	*read_data(char *av);

char	*line_check(char *av)
{
	char	*ret;
	int		i;

	i = 0;
	ret = read_data(av);
	printf("%s\n is my function working?", ret);
	while (i < *ret)
	{
		printf("%d", i);
		i++;
	}

	return (ret);
}
