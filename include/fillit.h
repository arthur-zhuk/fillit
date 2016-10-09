/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 21:57:52 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/08 18:12:43 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>

int		check_grid_lines(char *input);
int		last_char_nl(char *input);

char	*line_check(char *av);

#endif
