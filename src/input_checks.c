
#include "../include/libft.h"
#include "../include/fillit.h"


int		check_grid_lines(char *input)
{
	int		new_lines;
	int		i;

	i = 0;
	new_lines = 0;
	while (input[i])
	{
		//printf("i: %d, %c, nl: %d\n", i, input[i], new_lines);
		if (input[i] == '\n')
		{
			new_lines++;
			// printf("nl: %d\n", new_lines);
		}

		if ((input[i] == '\n' && input[i + 1] == '\n') || (input[i + 1] == '\0'))
		{
			printf("new_lines: %d\n", new_lines);
			if (new_lines != 4)
				return (0);
			printf("~~~~~~~~~~~~~~~new grid~~~~~~~~~~~~~~\n");
			new_lines = 0;
			i++;
		}
		i++;
	}
	return (1);
}

int		last_char_nl(char *input)
{	
	int		len;

	len = ft_strlen(input);
	if (input[len] != '\n')
		return (0);
	return (1);
}













