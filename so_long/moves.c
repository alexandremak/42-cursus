/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:28:48 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 02:39:32 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_posnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		put_posnbr(n / 10);
		put_posnbr(n % 10);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

int	check_move(t_windows *window, int y, int x)
{
	if (window->map.mtrx[y][x] == '1')
		return (0);
	if (window->map.mtrx[y][x] == 'C')
	{
		window->map.collects--;
		return (1);
	}
	if (window->map.mtrx[y][x] == 'E')
	{
		if (window->map.collects == 0)
			return (-1);
		return (1);
	}
	return (1);
}

void	exec_move(t_windows *win, int y, int x)
{
	win->map.mtrx[y][x] = 'P';
	if (win->map.ply_y == win->map.ext_y && win->map.ply_x == win->map.ext_x)
		win->map.mtrx[win->map.ext_y][win->map.ext_x] = 'E';
	else
		win->map.mtrx[win->map.ply_y][win->map.ply_x] = '0';
	win->map.ply_y = y;
	win->map.ply_x = x;
	win->map.moves++;
}

void	move(t_windows *window, int y, int x)
{
	if (check_move(window, y, x) == 1)
	{
		exec_move(window, y, x);
		build_map(window);
		write(1, "Moves: ", 7);
		put_posnbr(window->map.moves);
		write(1, "\n", 1);
	}
	if (check_move(window, y, x) == -1)
		close_window(window);
}
