/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 21:37:20 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/07 21:59:44 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		check_grid_size(char *input)
{
	int		new_lines;
	int		spots;
	int		i;

	i = 0;
	new_lines = 0;
	spots = 0;
	while (input[i])
	{
		printf("i: %d, input[i]: %c", i, input[i]);
		if (input[i] == '\n')
		{
			if (spots != 4)
				return (0);
			new_lines++;
		}
		if ((input[i] == '\n' && input[i] == '\n') || input[i + 1] == '\0')
		{
			if (new_lines != 6)
				return (0);
			else
				new_lines = 0;
		}
		i++;
	}
	return (1);
}