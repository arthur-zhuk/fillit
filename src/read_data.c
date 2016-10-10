#include "../include/libft.h"
#include "../include/fillit.h"
#include <fcntl.h>

char	*read_data(char *av);
char	*input_data(char *av);
int		line_check(char *av);
int		line_cnt(char *av);

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file");
		return (0);
	}
	ft_putstr(argv[1]);
	ft_putstr("\n");
	input_data(argv[1]);
	printf("\n\n");
	printf("%d double \\n's \n", line_check(argv[1]));
	if (line_cnt(argv[1]))
		printf("%d - This tetri is 16 chars in size\n", line_cnt(argv[1]));
	else
		printf("This tetri isn't 16 chars in size");
	return (0);
}

char	*input_data(char *av)
{
	char	*ret;

	ret = read_data(av);
	printf("------\n");
	printf("%s\n", ret);
	printf("------\n");
	printf("end with nl: %d\n", last_char_nl(ret));
	printf("grid check resutl: %d", check_grid_lines(ret));

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
