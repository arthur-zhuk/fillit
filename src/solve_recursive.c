#include "../include/libft.h"
#include "../include/fillit.h"

int		ft_make_map(char **piece_list)
{
	char	**grid;
	int		size;

	size = ft_sqrt((ft_strlen_dub(piece_list) * 4));
	while (1)
	{
		grid = h_make_grid(size);
		if (ft_recursive(piece_list, grid))
		{
			print_mino(grid);
			return (1);
		}
		else
			free(grid);
		size++;
	}
	return (0);
}

int		ft_recursive(char **piece_list, char **grid)
{
	t_coord		*gc;

	gc = (t_coord *)malloc(sizeof(t_coord));
	gc -> x = -1;
	gc -> y = 0;
	gc -> size = ft_strlen(grid[0]);
	if (piece_list[0] == 0)
		return (1);
	while (h_iterate_grid_coord(gc))
	{
		if (solve_entrance(grid, piece_list, gc))
		{
			if (ft_recursive(ft_new_piece_list(piece_list, 0), grid))
			{
				free(piece_list);
				return (1);
			}
			else
				ft_unplace_piece(grid, piece_list[0]);
		}
	}
	return (0);
}

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
	char	**new_piece;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = ft_strlen_dub(piece_list);
	new_piece = (char **)malloc(sizeof(char *) * (len));
	while (piece_list[i])
	{
		new_piece[j] = (char *)malloc(sizeof(char) * 17);
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

int		ft_strlen_dub(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}































