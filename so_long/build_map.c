/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:40:51 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 03:11:02 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	Checks the key pressed and prints the image of the player with that 
	direction */
void	insert_player_img(int y, int x, t_windows *w)
{
	if (w->map.ply_y == w->map.ext_y && w->map.ply_x == w->map.ext_x)
		mlx_put_image_to_window(w->mlx, w->win, w->img.pe, x * PX, y * PX);
	else if (w->map.last_key == 'w')
		mlx_put_image_to_window(w->mlx, w->win, w->img.pw, x * PX, y * PX);
	else if (w->map.last_key == 'a')
		mlx_put_image_to_window(w->mlx, w->win, w->img.pa, x * PX, y * PX);
	else if (w->map.last_key == 'd')
		mlx_put_image_to_window(w->mlx, w->win, w->img.pd, x * PX, y * PX);
	else
		mlx_put_image_to_window(w->mlx, w->win, w->img.ps, x * PX, y * PX);
}

/* 	Checks the char of the x/y position in the map and prints the image in the
	windows */
void	insert_img(char c, int x, int y, t_windows *w)
{
	if (c == 'C')
		mlx_put_image_to_window(w->mlx, w->win, w->img.cltb, x * PX, y * PX);
	if (c == 'E')
	{
		if (w->map.collects == 0)
			mlx_put_image_to_window(w->mlx, w->win, w->img.eo, x * PX, y * PX);
		else
			mlx_put_image_to_window(w->mlx, w->win, w->img.e, x * PX, y * PX);
	}
	if (c == 'P')
		insert_player_img(y, x, w);
	if (c == '0')
		mlx_put_image_to_window(w->mlx, w->win, w->img.space, x * PX, y * PX);
	if (c == '1')
		mlx_put_image_to_window(w->mlx, w->win, w->img.wall, x * PX, y * PX);
}

/*	Checks the map matrix and inserts the image of the correspondent char */
void	build_map(t_windows *window)
{
	int	y;
	int	x;

	y = 0;
	while (y < window->map.height)
	{
		x = 0;
		while (x < window->map.width)
		{
			insert_img(window->map.mtrx[y][x], x, y, window);
			x++;
		}
		y++;
	}
}
