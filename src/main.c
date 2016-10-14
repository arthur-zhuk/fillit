#include "../include/libft.h"
#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	char	*ret;
	char	**z;
	int		i;
	int		j;

	j = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file");
		return (0);
	}
	if (!(ret = input_data(argv[1])))
	{
	   	printf("**** Main: tests returned FAIL\n\n");
		return (0);
	}
	else
	{
		printf("**** Main: tests returned SUCCESS\n\n");
	}
	// printf("input data: %s\n" , ret);
	z = (char **)malloc(sizeof(char *) * tetrimino_count(ret));
	i = 0;
	while (ret[i])
	{
		if (i % 16 == 0)
		{
			z[j] = (char *)malloc(17);
			ft_strncpy(z[j], &ret[i], 16);
			// print_mino(make_mino(z[j]));
			j++;
		}
		i++;
	}
	z[i] = 0;
	//ft_puttab(z);
	return (0);
}



// ".....AAA...A...." ".B...BB...B....." "....CCC..C......" "DDDD............" "..........EE..EE" ".....FFF...F...." "......G...G...GG"




	//argv = NULL; // edit this later

//...#...#...#...#
	





