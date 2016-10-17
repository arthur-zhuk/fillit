#include "../include/libft.h"
#include "../include/fillit.h"

char	**input_data(char *av)
{
	char	*ret;
	char	**ret_two_d;
	int		num_minos;

	ret = read_data(av);
	if (ret == 0)
	{
		free(ret);
		return (0);
	}
	if (!(num_minos = tetrimino_count(ret)))
		graceful_exit(ret);
	if (!(nl_check(ret)))
		graceful_exit(ret);
	if (!(dot_hash_check(ret)))
		graceful_exit(ret);
	ret = rm_nl(ret, num_minos);
	if (!(pre_shape_check(ret)))
		graceful_exit(ret);
	ret = hash_to_letter(ret);
	ret_two_d = make_two_d(num_minos, 16, ret);
	return (ret_two_d);
}

char	*read_data(char *av)
{
	char	*buf;
	int		fd;
	int		ret;

	buf = (char *)malloc(sizeof(char) * 10000);
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("could not open input\n");
		return (0);
	}
	ret = read(fd, buf, 10000);
	if (ret == -1)
	{
		ft_putstr("could not read input\n");
		return (0);
	}
	buf[ret] = '\0';
	close(fd);
	return (buf);
}

void	graceful_exit(char *str)
{
	ft_putstr("error\n");
	free(str);
	exit(0);
}
