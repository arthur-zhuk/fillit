#include "../include/libft.h"
#include "../include/fillit.h"

// Creates the grid takes the 'size' as an arg. Puts all dots in it.
// calls ft_recursive. if ft_recurisve fails, it increases grid size.
int		ft_make_map(char **piece_list)
{
	char	**grid;
	int		size;
	//print_mino(piece_list);

	size = ft_sqrt((ft_strlen_dub(piece_list) * 4));
	while (1)
	{
		grid = h_make_grid(size);
		if (ft_recursive(piece_list, grid))
			return (1);
		else
		{
		//	printf("grid fail");
			free(grid);
		}
		size++;
		//printf("size: %d\n", size);
	}

	return (0);
}

// while there are pieces left to place.
// if piece fits
// call recursion on next line.
// if recurision is successful i.e: grid solved. free the piece.
// if recursion is not successful then unplace piece.
// continue until you've tried all of the pieces.

int		ft_recursive(char **piece_list, char **grid)
{
	// printf("in recurssive\n");
	int		i;

	i = 0;
	if (piece_list[i] == 0)
		return (1);
	while (piece_list[i] != '\0')
	{
//		printf("mino: \n");
//		print_mino(make_mino(piece_list[i]));
//		printf("grid: \n");
//		print_mino(grid);
//		printf("piece_list: \n");
//		print_mino(piece_list);

		if (solve_entrance(grid, piece_list, i))
		{
			// printf("place piece SUCCESS\n");
			// print_mino(grid);
			if (ft_recursive(ft_new_piece_list(piece_list, i), grid))
			{
				// print_mino(grid);
				free(piece_list);
				return (1);
			}
			else
			{
				// printf("unplace piece before:\n");
				// print_mino(grid);
				ft_unplace_piece(grid, piece_list[i]);
				// printf("unplace piece after:\n");
				// print_mino(grid);
			}
		}
		else
		{
			// printf("place piece fail\n");
			// printf("return 0 \n");
			// printf("next operation should be unplace piece one level up\n");

			return (0);
		}
		i++;
	}
	return (0);
}

/*
** removes the current piece from the grid.  in the event that the
** resultant grid is a failure, and it is necessary for this iteration
** to try a new piece
*/

void	ft_unplace_piece(char **grid, char *piece)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (piece[i] == '.')
		i++;
	// printf("remove letter: %c\n", piece[i]);
	while (grid[j])
	{
		// printf("%s\n", grid[j]);
		k = 0;
		while (grid[j][k])
		{
			if (grid[j][k] == piece[i])
				grid[j][k] = '.';
			k++;
		}
		j++;
	}
}

char	**ft_new_piece_list(char **piece_list, int piece_index)
{
	// printf("ft_new_piece_list: entrance.  index: %d\n", piece_index);
	// print_mino(piece_list);
	char	**new_piece;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = ft_strlen_dub(piece_list);
	// printf("after len\n");
	// -1 in the malloc to account for the piece that we are going to
	// skip over in te new string.
	new_piece = (char **)malloc(sizeof(char *) * (len));
	// printf("after malloc\n");
	while (piece_list[i])
	{
		// printf("i: %d\n", i);
		// printf("index: %d\n", piece_index);
		// printf("j: %d\n", j);
		// printf("len: %d\n", len);
		// printf("piece %s\n" , piece_list[i]);
		new_piece[j] = (char *)malloc(sizeof(char) * 17);
		// printf("after inner malloc\n");
		if (i != piece_index)
		{
			// printf("before assigning new piece\n");
			new_piece[j] = ft_strdup(piece_list[i]);
			// printf("after assiging new piece\n");
			// printf("new piece %s\n" , new_piece[j]);
			i++;
			j++;
		}
		else
			i++;
	}
	new_piece[j] = 0;
	//printf("ft_new_piece_list: exit\n\n");
	return (new_piece);
}

int		ft_strlen_dub(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}































