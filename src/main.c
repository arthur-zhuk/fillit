#include "../include/libft.h"
#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	char	**ret;

	if (argc != 2)
	{
		// ft_putstr("usage: ./fillit source_file");
		return (0);
	}
	if (!(ret = input_data(argv[1])))
	{
	   	// printf("**** Main: tests returned FAIL\n\n");
		return (0);
	}
	else
		// printf("**** Main: tests returned SUCCESS\n\n");

	// printf("strlen dub: %d\n", ft_strlen_dub(ret));
	// print_mino(ret);
	ft_make_map(ret);
	return (0);
}

