#include "../include/libft.h"
#include "../include/fillit.h"
#include <fcntl.h>
#include <errno.h>

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

	// int		s;
	// int		shape;

	ret = read_data(av);
	// printf("nl check: %d", nl_check(ret, s));
	// Arthur: add function that checks the new line between each mino
	ret = rm_nl(ret);
	printf("all good shapes? : %d", pre_shape_check(ret));
	//s = tetrimino_count(ret);
	// printf("num minos: %d\n", s);

	// shape = shape_check("......##.##.....", 6, 100, 0);
	// shape = shape_check(".#..###.........", 1, 100, 0);
	// shape = shape_check(".....###.#......", 5, 100, 0);
	// shape = shape_check("#...#...#...#...", 0, 100, 0);
	// printf("shape check: %d", shape);
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
		error_check();
		ft_putstr("could not open input\n");
		return (0);
	}
	ret = read(fd, buf, 10000);
	close(fd);
	return (buf);
}


void	error_check(void)
{
	if (errno == ENAMETOOLONG)
		printf("File name too long\n");
	else if (errno == ENOENT)
		printf("No such file or directory\n");
	else if (errno == ETXTBSY)
		printf("Text file busy\n");
	else if (errno == EACCES)
		printf("Permission denied\n");
	else if (errno == EFBIG)
		printf("File too large\n");
	else if (errno == EISDIR)
		printf("Is a directory\n");
	else
		printf("Unknown error\n");
}


// gcc src/read_data.c src/input_index.c -I include/fillit.h include/libft.h -L. -lft