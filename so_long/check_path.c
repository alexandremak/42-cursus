/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:40:08 by amak              #+#    #+#             */
/*   Updated: 2023/09/29 00:19:58 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**mapcpy(t_windows *window)
{
	char **dst;
	int	i;
	
	i = 0;
	dst = (char **)malloc(sizeof(char *) * (window->map.height + 1));
	if (!dst)
		return (NULL);
	while (i < window->map.height)
	{
		dst[i] = ft_strdup(window->map.map_mtrx[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == 'F' || map[y][x] == '1')
		return;
	if (map[y][x] == 'C' || map[y][x] == '0' || map[y][x] == 'E' || map[y][x] == 'P')
		map[y][x] = 'F';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}

void	check_path(t_windows *window)
{
	char	**copy_map;
	int		y;
	int		x;

	copy_map = mapcpy(window);
	if (!copy_map)
		return;
	y = 0;
	flood_fill(copy_map, window->map.p_ypos, window->map.p_xpos);
	while (y < window->map.height)
	{
		x = 0;
		while (x < window->map.width)
		{
			if (copy_map[y][x] == 'C' || copy_map[y][x] == 'E')
			{
				write(2, "Error: Map with no valid path to collectible or exit!\n", 54);
				free_map(copy_map);
				close_window(window);
			}
			x++;
		}
		y++;
	}
	free_map(copy_map);
}
