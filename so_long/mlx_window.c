/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:51:08 by amak              #+#    #+#             */
/*   Updated: 2023/09/26 22:36:37 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_windows *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->map.width * PIXELS, window->map.height * PIXELS, "Stones & Lava: Dungeon Escape");
}

int	close_window(t_windows *window)
{
	write(1, "Window closed!\n", 15);
	free_map(window->map.map_mtrx);
	free_imgs(window);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	write(1, " >>> fim <<<\n", 13);
	exit(0);
}

int	key_press(int keycode, t_windows *window)
{
	if (keycode == ESC)
		close_window(window);
	if (keycode == W)
		moving(window, window->map.p_ypos - 1, window->map.p_xpos);
	if (keycode == S)
		moving(window, window->map.p_ypos + 1, window->map.p_xpos);
	if (keycode == A)
		moving(window, window->map.p_ypos, window->map.p_xpos - 1);
	if (keycode == D)
		moving(window, window->map.p_ypos, window->map.p_xpos + 1);
	return (0);
}
