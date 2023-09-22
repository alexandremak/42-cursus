/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:28:48 by amak              #+#    #+#             */
/*   Updated: 2023/09/22 15:43:09 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_windows *window, int y, int x)
{
	if (window->map.map_mtrx[y][x] == '1')
		return (0);
	if (window->map.map_mtrx[y][x] == 'C')
	{
		window->map.collects--;
		return (1);
	}
	if (window->map.map_mtrx[y][x] == 'E')
	{
		if (window->map.collects == 0)
			return (-1);
		return (1);
	}
	return (1);
}

void	exec_move(t_windows *window, int y, int x)
{
	window->map.map_mtrx[y][x] = 'P';
	window->map.map_mtrx[window->map.p_ypos][window->map.p_xpos] = '0';
	window->map.p_ypos = y;
	window->map.p_xpos = x;
}
