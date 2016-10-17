/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 12:09:19 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/17 12:19:45 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fillit.h"

int		min_x_point(char **mino)
{
	int		i;
	int		j;
	int		x;

	x = 4;
	i = 0;
	j = 0;
	while (mino[i])
	{
		j = 0;
		while (mino[i][j])
		{
			if (mino[i][j] != '.' && j < x)
				x = j;
			j++;
		}
		i++;
	}
	return (x);
}

int		min_y_point(char **mino)
{
	int		i;
	int		j;
	int		y;

	y = 4;
	i = 0;
	j = 0;
	while (mino[i])
	{
		j = 0;
		while (mino[i][j])
		{
			if (mino[i][j] != '.' && i < y)
				y = i;
			j++;
		}
		i++;
	}
	return (y);
}

char	**make_two_d(int y, int x, char *data)
{
	int		i;
	int		j;
	int		k;
	char	**grid;

	i = 0;
	j = 0;
	k = 0;
	grid = (char **)malloc(sizeof(char *) * (y + 1));
	while (i < y)
	{
		grid[i] = (char *)malloc(sizeof(char) * (x + 1));
		j = 0;
		while (j < x)
		{
			grid[i][j] = data[k];
			j++;
			k++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = 0;
	free(data);
	return (grid);
}

char	**h_make_grid(int size)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	j = 0;
	grid = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		grid[i] = (char *)malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = 0;
	return (grid);
}

char	**make_mino(char *z)
{
	int		i;
	int		j;
	int		k;
	char	**mino;

	i = 0;
	j = 0;
	k = 0;
	mino = (char **)malloc(sizeof(char *) * (4 + 1));
	while (i < 4)
	{
		mino[i] = (char *)malloc(sizeof(char) * (4 + 1));
		j = 0;
		while (j < 4)
		{
			mino[i][j] = z[k];
			j++;
			k++;
		}
		mino[i][j] = '\0';
		i++;
	}
	mino[i] = 0;
	return (mino);
}
