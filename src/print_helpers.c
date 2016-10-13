#include "../include/libft.h"
#include "../include/fillit.h"
#include <stdio.h>



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
			printf("%c", mino[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

