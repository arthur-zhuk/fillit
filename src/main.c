/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 22:08:50 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/17 13:04:05 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	char	**ret;

	if (argc != 2)
		return (0);
	if (!(ret = input_data(argv[1])))
		return (0);
	ft_make_map(ret);
	return (0);
}
