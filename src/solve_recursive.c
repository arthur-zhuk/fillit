#include "../include/libft.h"
#include "../include/fillit.h"


int		ft_make_map(char **piece_list)
{
	char	**grid;
	int		size;

	size = 2;
	while (size < 100)
	{
		grid = h_make_grid(size);
		if (ft_recursive(piece_list, grid))
			return (1);
		else
		{
			free(grid);
			size++;
		}
	}
	return (0);
}

int		ft_recursive(char **piece_list, char **grid)
{	
	int		i;

	i = 0;
	while (piece_list[i] != '\0')
	{
		if (ft_place_piece(piece_list, i))
		{
			if (ft_recursive(ft_new_piece_list(piece_list, i), grid))
			{
				free(piece_list);
				return (1);
			}
			else
				ft_unplace_piece(grid, piece_list[i]);
		}
		else
			return (0);
		i++;
	}
	return (1);
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
	while (grid[j])
	{
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
	char	**new_piece;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = ft_strlen_dub(piece_list);
	// -1 in the malloc to account for the piece that we are going to 
	// skip over in te new string.
	new_piece = (char **)malloc(sizeof(char *) * (len - 1));
	while (piece_list[i] != '\0')
	{
		new_piece[j] = (char *)malloc(sizeof(char) * 5);
		if (i != piece_index)
		{
			new_piece[j] = ft_strdup(piece_list[i]);
			i++;
			j++;
		} 
		else
			i++;
	}
	new_piece[j] = 0;
	return (new_piece);
}



size_t	ft_strlen_dub(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}































