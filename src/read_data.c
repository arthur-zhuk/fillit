#include "../include/libft.h"
#include "../include/fillit.h"
#include <fcntl.h>

char	*read_data(char *av);
char	*input_data(char *av);
int		line_check(char *av);

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file");
		return (0);
	}
	input_data(argv[1]);
	return (0);
}

char	*input_data(char *av)
{
	char	*ret;
	int		s;

	ret = read_data(av);
	s = tetrimino_count(ret);
	printf("num minos: %d\n", s);
	printf("nl check: %d", nl_check(ret, s));

	// do checks
	// reduce mino grids
		// if only '\n', '.', '#'

		// num lines
		// num columns
		// propper fomatting (i.e. 1 line between each)
	return (ret);
}


char	*read_data(char *av)
{
	char	*buf;
	int		fd;
	int		ret;

	buf = (char *)malloc(sizeof(char) * 10000);
	/*ft_putstr(av);*/
	/*ft_putstr("\n");*/
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("could not open input\n");
		return (0);
	}
	ret = read(fd, buf, 10000);

	return (buf);
}
