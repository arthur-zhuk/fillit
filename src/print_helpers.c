#include "../include/libft.h"
#include "../include/fillit.h"

void	print_mino(char **mino)
{
	int		i;
	int		j;

	i = 0;
	while (mino[i])
	{
		j = 0;
		while (mino[i][j])
		{
			ft_putchar(mino[i][j]);
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

void	prnt_str_to_grid(char *z)
{
	int		i;

	i = 0;
	while (z[i] != '\0')
	{
		ft_putchar(z[i]);
		if (i % 4 == 3)
			ft_putstr("\n");
		i++;
	}
}
