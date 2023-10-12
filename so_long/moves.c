/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:28:48 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 22:40:29 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	Prints a int number in screen output */
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

/*	Checks if a position is a valid move for the player, returns -1 if there 
	are no collectibles and the exit position is to end game */
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

/*	Execute the movement for the player, loads the new position in the 
	structure and increments the moves number.
	NOTE: if the player new position and exit position are the same,
	the map matrix has only the 'E' char */
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

/*	The main move function checks if the new move position is valid, prints the
	number of moves and builds the map in screen. Ends the game if it is that
	case */
void	move(t_windows *window, int y, int x)
{
	if (check_move(window, y, x) == 1)
	{
		exec_move(window, y, x);
		write(1, "Moves: ", 7);
		put_posnbr(window->map.moves);
		write(1, "\n", 1);
	}
	build_map(window);
	if (check_move(window, y, x) == -1)
		close_window(window);
}
