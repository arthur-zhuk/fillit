#include "../include/libft.h"
#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	char	**ret;

	if (argc != 2)
		return (0);
	if (!(ret = input_data(argv[1])))
		return (0);
	ft_make_map(ret);
	return (0);
}
