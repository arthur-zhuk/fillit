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
	prnt_str2grid(ret);
	return (0);
}
