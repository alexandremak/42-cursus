/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:51:08 by amak              #+#    #+#             */
/*   Updated: 2023/09/25 23:49:04 by amak             ###   ########.fr       */
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
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit(0);
}

int	key_press(int keycode, t_windows *window)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		close_window(window);
	return (0);
}
