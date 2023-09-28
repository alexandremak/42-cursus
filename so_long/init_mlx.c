/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:51:08 by amak              #+#    #+#             */
/*   Updated: 2023/09/28 21:19:54 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_windows *window)
{
	int		size;

	window->images.collect = mlx_xpm_file_to_image(window->mlx_ptr, "img_collect.xpm", &size, &size);
	window->images.exit = mlx_xpm_file_to_image(window->mlx_ptr, "img_exit.xpm", &size, &size);
	window->images.player = mlx_xpm_file_to_image(window->mlx_ptr, "img_player.xpm", &size, &size);
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

int		key_press(int keycode, t_windows *window)
{
	if (keycode == ESC)
		close_window(window);
	if (keycode == W)
		move(window, window->map.p_ypos - 1, window->map.p_xpos);
	if (keycode == S)
		move(window, window->map.p_ypos + 1, window->map.p_xpos);
	if (keycode == A)
		move(window, window->map.p_ypos, window->map.p_xpos - 1);
	if (keycode == D)
		move(window, window->map.p_ypos, window->map.p_xpos + 1);
	return (0);
}
