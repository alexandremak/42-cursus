/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:51:08 by amak              #+#    #+#             */
/*   Updated: 2023/10/11 20:36:35 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_windows *window)
{
	int		size;

	window->images.collect = mlx_xpm_file_to_image(window->mlx_ptr, "img_collect.xpm", &size, &size);
	window->images.exit = mlx_xpm_file_to_image(window->mlx_ptr, "img_exit.xpm", &size, &size);
	window->images.exit_open = mlx_xpm_file_to_image(window->mlx_ptr, "img_exit_open.xpm", &size, &size);
	window->images.player_s = mlx_xpm_file_to_image(window->mlx_ptr, "img_player_s.xpm", &size, &size);
	window->images.player_w = mlx_xpm_file_to_image(window->mlx_ptr, "img_player_w.xpm", &size, &size);
	window->images.player_a = mlx_xpm_file_to_image(window->mlx_ptr, "img_player_a.xpm", &size, &size);
	window->images.player_d = mlx_xpm_file_to_image(window->mlx_ptr, "img_player_d.xpm", &size, &size);
	window->images.space = mlx_xpm_file_to_image(window->mlx_ptr, "img_space.xpm", &size, &size);
	window->images.wall = mlx_xpm_file_to_image(window->mlx_ptr, "img_wall.xpm", &size, &size);
	window->images.player_exit = mlx_xpm_file_to_image(window->mlx_ptr, "img_player_exit.xpm", &size, &size);
}

void	init_mlx(t_windows *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->map.width * PIXELS, window->map.height * PIXELS, "Stones & Lava: Dungeon Escape");
	init_imgs(window);
}

int	key_press(int keycode, t_windows *window)
{
	if (keycode == ESC)
		close_window(window);
	if (keycode == W)
	{
		window->map.last_key = 'w';
		move(window, window->map.p_ypos - 1, window->map.p_xpos);
	}
	if (keycode == S)
	{
		window->map.last_key = 's';
		move(window, window->map.p_ypos + 1, window->map.p_xpos);
	}
	if (keycode == A)
	{
		window->map.last_key = 'a';
		move(window, window->map.p_ypos, window->map.p_xpos - 1);
	}
	if (keycode == D)
	{
		window->map.last_key = 'd';
		move(window, window->map.p_ypos, window->map.p_xpos + 1);
	}
	return (0);
}
