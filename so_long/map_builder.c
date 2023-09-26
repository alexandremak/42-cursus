/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:40:51 by amak              #+#    #+#             */
/*   Updated: 2023/09/26 22:19:45 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_imgs(t_windows *window)
{
	int		size;

	window->images.collect = mlx_xpm_file_to_image(window->mlx_ptr, "img_collect.xpm", &size, &size);
	window->images.exit = mlx_xpm_file_to_image(window->mlx_ptr, "img_exit.xpm", &size, &size);
	window->images.player = mlx_xpm_file_to_image(window->mlx_ptr, "img_player.xpm", &size, &size);
	window->images.space = mlx_xpm_file_to_image(window->mlx_ptr, "img_space.xpm", &size, &size);
	window->images.wall = mlx_xpm_file_to_image(window->mlx_ptr, "img_wall.xpm", &size, &size);
	window->images.player_exit = mlx_xpm_file_to_image(window->mlx_ptr, "img_player_exit.xpm", &size, &size);
}

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

void	free_imgs(t_windows *window)
{
	mlx_destroy_image(window->mlx_ptr, window->images.collect);
	mlx_destroy_image(window->mlx_ptr, window->images.exit);
	mlx_destroy_image(window->mlx_ptr, window->images.player);
	mlx_destroy_image(window->mlx_ptr, window->images.space);
	mlx_destroy_image(window->mlx_ptr, window->images.wall);
	mlx_destroy_image(window->mlx_ptr, window->images.player_exit);
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
