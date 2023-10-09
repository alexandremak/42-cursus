/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:25:33 by amak              #+#    #+#             */
/*   Updated: 2023/10/09 20:44:47 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	free_imgs(t_windows *window)
{
	if (window->images.collect)
		mlx_destroy_image(window->mlx_ptr, window->images.collect);
	if (window->images.collect)
		mlx_destroy_image(window->mlx_ptr, window->images.exit);
	if (window->images.collect)
		mlx_destroy_image(window->mlx_ptr, window->images.player);
	if (window->images.collect)
		mlx_destroy_image(window->mlx_ptr, window->images.space);
	if (window->images.collect)
		mlx_destroy_image(window->mlx_ptr, window->images.wall);
	if (window->images.collect)
		mlx_destroy_image(window->mlx_ptr, window->images.player_exit);
}

int	free_all(t_windows *window)
{
	if (window->map.map_mtrx)
		free_map(window->map.map_mtrx);
	free_imgs(window);
	if (window->win_ptr)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	if (window->mlx_ptr)
	{
		mlx_destroy_display(window->mlx_ptr);
		free(window->mlx_ptr);
	}
	return (1);
}

void	close_window(t_windows *window)
{
	free_all(window);
	exit(1);
}
