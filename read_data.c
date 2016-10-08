/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:10:23 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/08 14:43:41 by azhuk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

char	*read_data(char *av);
char	*input_data(char *av);

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
	return (0);
}

char	*input_data(char *av)
{
	char	*ret;

	ret = read_data(av);
	printf("------\n");
	printf("%s\n", ret);
	printf("------\n");
	printf("grid check resutl: %d", check_grid_lines(ret));

	// do checks
	// reduce mino grids
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
	ft_putstr(av);
	ft_putstr("\n");
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("could not open input\n");
		return (0);
	}
	ret = read(fd, buf, 10000);

	return (buf);
}
