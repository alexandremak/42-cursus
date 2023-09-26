/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:28:48 by amak              #+#    #+#             */
/*   Updated: 2023/09/26 22:03:18 by amak             ###   ########.fr       */
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
	if (window->map.p_ypos == window->map.e_ypos && window->map.p_xpos == window->map.e_xpos)
		window->map.map_mtrx[window->map.e_ypos][window->map.e_xpos] = 'E';
	else
		window->map.map_mtrx[window->map.p_ypos][window->map.p_xpos] = '0';
	window->map.p_ypos = y;
	window->map.p_xpos = x;
	window->map.count_moves++;
}

void 	moving(t_windows *window, int y, int x)
{
	if (check_move(window, y, x) == 1)
	{
		exec_move(window, y, x);
		build_map(window);
	}
	if (check_move(window, y, x) == -1)
		close_window(window);
}
