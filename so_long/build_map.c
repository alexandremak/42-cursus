/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:40:51 by amak              #+#    #+#             */
/*   Updated: 2023/09/28 20:46:09 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	insert_img(char c, int x, int y, t_windows *window)
{
	if (c == 'C')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->images.collect, x * PIXELS, y * PIXELS);
	if (c == 'E')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->images.exit, x * PIXELS, y * PIXELS);
	if (c == 'P')
	{
		if (window->map.p_ypos == window->map.e_ypos && window->map.p_xpos == window->map.e_xpos)
			mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->images.player_exit, x * PIXELS, y * PIXELS);
		else
			mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->images.player, x * PIXELS, y * PIXELS);
	}
	if (c == '0')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->images.space, x * PIXELS, y * PIXELS);
	if (c == '1')
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->images.wall, x * PIXELS, y * PIXELS);
}

void	build_map(t_windows *window)
{
	int y;
	int x;
	
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
