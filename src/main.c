#include "../include/libft.h"
#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	char	*ret;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file");
		return (0);
	}
	ret = input_data(argv[1]);
	if (!ret)
		return (0);
	// prnt_str2grid(ret);
	// printf("%d double \\n's \n", line_check(argv[1]));
	// if (line_cnt(argv[1]))
	// printf("%d - This tetri is 16 chars in size\n", line_cnt(argv[1]));
	// else
		// printf("This tetri isn't 16 chars in size");

	return (0);
}