/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:51:08 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 22:18:40 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	Intialize the game images pointer with the images files */
void	init_imgs(t_windows *win)
{
	int		s;

	win->img.cltb = mlx_xpm_file_to_image(win->mlx, "img_cltb.xpm", &s, &s);
	win->img.e = mlx_xpm_file_to_image(win->mlx, "img_e.xpm", &s, &s);
	win->img.eo = mlx_xpm_file_to_image(win->mlx, "img_eo.xpm", &s, &s);
	win->img.ps = mlx_xpm_file_to_image(win->mlx, "img_ps.xpm", &s, &s);
	win->img.pw = mlx_xpm_file_to_image(win->mlx, "img_pw.xpm", &s, &s);
	win->img.pa = mlx_xpm_file_to_image(win->mlx, "img_pa.xpm", &s, &s);
	win->img.pd = mlx_xpm_file_to_image(win->mlx, "img_pd.xpm", &s, &s);
	win->img.space = mlx_xpm_file_to_image(win->mlx, "img_space.xpm", &s, &s);
	win->img.wall = mlx_xpm_file_to_image(win->mlx, "img_wall.xpm", &s, &s);
	win->img.pe = mlx_xpm_file_to_image(win->mlx, "img_pe.xpm", &s, &s);
}

/*	Intialize the mlx interface and creates the windows and images */
void	init_mlx(t_windows *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->map.width * PX, \
	window->map.height * PX, "Stones & Lava: Dungeon Escape");
	init_imgs(window);
}

/*	Check what keyboard key is pressed and executes movement if possible */
int	key_press(int keycode, t_windows *window)
{
	if (keycode == ESC)
		close_window(window);
	if (keycode == W)
	{
		window->map.last_key = 'w';
		move(window, window->map.ply_y - 1, window->map.ply_x);
	}
	if (keycode == S)
	{
		window->map.last_key = 's';
		move(window, window->map.ply_y + 1, window->map.ply_x);
	}
	if (keycode == A)
	{
		window->map.last_key = 'a';
		move(window, window->map.ply_y, window->map.ply_x - 1);
	}
	if (keycode == D)
	{
		window->map.last_key = 'd';
		move(window, window->map.ply_y, window->map.ply_x + 1);
	}
	return (0);
}
