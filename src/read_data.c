#include "../include/libft.h"
#include "../include/fillit.h"

char	*input_data(char *av)
{
	char	*ret;
	int		check[4];
	int		num_minos;
	int		i;

	i = -1;
	ret = read_data(av);

	num_minos = tetrimino_count(ret);
	check[0] = nl_check(ret, num_minos);
	check[1] = dot_hash_check(ret);
	ret = rm_nl(ret);
	check[2] = pre_shape_check(ret);
	if (!input_error(check))
		return (0);	
	ret = hash_to_letter(ret);
	

	return (ret);
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


int		input_error(int	*check)
{
	int		i;

	i = 0;
	if (check[0] == 0)
		ft_putstr("failed new line check\n");
	if (check[1] == 0)
		ft_putstr("failed dot hash check\n");
	if (check[2] == 0)
		ft_putstr("failed shape check\n");
	while (i < 3)
	{
		if (check[i] == 0)
			return (0);
		i++;
	}
	return (1);
}


// gcc src/main.c src/read_data.c src/input_index.c src/input_helpers.c -I include/fillit.h include/libft.h -L. -lft