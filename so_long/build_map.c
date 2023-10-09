/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:40:51 by amak              #+#    #+#             */
/*   Updated: 2023/10/09 22:46:43 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_img(char c, int x, int y, t_windows *win)
{
	if (c == 'C')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->images.collect, x * PIXELS, y * PIXELS);
	if (c == 'E')
	{
		if (win->map.collects == 0)	
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->images.exit_open, x * PIXELS, y * PIXELS);
		else
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->images.exit, x * PIXELS, y * PIXELS);
	}
	if (c == 'P')
	{
		if (win->map.p_ypos == win->map.e_ypos && win->map.p_xpos == win->map.e_xpos)
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->images.player_exit, x * PIXELS, y * PIXELS);
		else
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->images.player, x * PIXELS, y * PIXELS);
	}
	if (c == '0')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->images.space, x * PIXELS, y * PIXELS);
	if (c == '1')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->images.wall, x * PIXELS, y * PIXELS);
}

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
			insert_img(window->map.map_mtrx[y][x], x, y, window);
			x++;
		}
		y++;
	}
}
