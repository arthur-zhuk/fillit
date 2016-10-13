#include "../include/libft.h"
#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	// char	*ret;
	char	**z;
	int		i;

	// ret = input_data(argv[1]);

	z = (char **)malloc(sizeof(char *) * 5);
	i = 0;
	while (i < 4)
	{
		z[i] = (char *)malloc(17);
		printf("%s\n" , argv[i + 1]);
		z[i] = argv[i + 1];
		i++;
	}
	z[i] = 0;
	printf("here\n");
	ft_puttab(z);
	ft_make_map(z);


	// if (!ret)
	// 	return (0);
	return (0);
}



// ".....AAA...A...." ".B...BB...B....." "....CCC..C......" "DDDD............"






	//argv = NULL; // edit this later

//...#...#...#...#
	




	/*if (argc != 2)*/
	/*{*/
		/*ft_putstr("usage: ./fillit source_file");*/
		/*return (0);*/
	/*}*/
