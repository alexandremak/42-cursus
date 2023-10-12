/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:25:33 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 02:55:48 by amak             ###   ########.fr       */
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
	if (window->img.cltb)
		mlx_destroy_image(window->mlx, window->img.cltb);
	if (window->img.e)
		mlx_destroy_image(window->mlx, window->img.e);
	if (window->img.eo)
		mlx_destroy_image(window->mlx, window->img.eo);
	if (window->img.ps)
		mlx_destroy_image(window->mlx, window->img.ps);
	if (window->img.pw)
		mlx_destroy_image(window->mlx, window->img.pw);
	if (window->img.pa)
		mlx_destroy_image(window->mlx, window->img.pa);
	if (window->img.pd)
		mlx_destroy_image(window->mlx, window->img.pd);
	if (window->img.space)
		mlx_destroy_image(window->mlx, window->img.space);
	if (window->img.wall)
		mlx_destroy_image(window->mlx, window->img.wall);
	if (window->img.pe)
		mlx_destroy_image(window->mlx, window->img.pe);
}

int	free_all(t_windows *window)
{
	if (window->map.mtrx)
		free_map(window->map.mtrx);
	free_imgs(window);
	if (window->win)
		mlx_destroy_window(window->mlx, window->win);
	if (window->mlx)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
	}
	return (1);
}

void	close_window(t_windows *window)
{
	free_all(window);
	exit(1);
}
