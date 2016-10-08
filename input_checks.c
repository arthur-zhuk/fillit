/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 21:37:20 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/08 15:00:49 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		strlen_c(char *s, char c);

int		check_grid_lines(char *input)
{
	int		new_lines;
	int		grids;
	int		spots;
	int		i;

	i = 0;
	new_lines = 0;
	spots = 0;
	grids = 0;
	while (input[i])
	{
		printf("i: %d, %c, nl: %d grids: %d\n", i, input[i], new_lines, grids);
		if (input[i] == '\n')
			new_lines++;
		if (input[i] == '\n' && input[i + 1] == '\n')
		{
			if (new_lines != 4)
				return (0);
			new_lines = 0;
			i++;
		}
		i++;
	}
	return (1);
}

// int		check_grid_lines(char *input)
// {
// 	int		new_lines;
// 	int		grids;
// 	int		spots;
// 	int		i;

// 	i = 0;
// 	new_lines = 0;
// 	spots = 0;
// 	grids = 0;
// 	while (input[i])
// 	{
// 		printf("i: %d, %c, spots: %d, nl: %d grids: %d\n", i, input[i], spots, new_lines, grids);
// 		if (input[i] == '.' || input[i] == '#')
// 			spots++;
// 		if (input[i] == '\n')
// 		{
// 			if (spots != 4)
// 				return (0);
// 			else
// 				spots = 0;
// 		}
// 		if (input[i] == '\n' && input[i + 1] == '\n')
// 		{
// 			i++;
// 			grids++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }














