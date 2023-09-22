/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 08:40:08 by amak              #+#    #+#             */
/*   Updated: 2023/09/22 12:21:39 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**mapcpy(t_map *map)
{
	char **dst;
	int	i;
	
	i = 0;
	dst = malloc(sizeof(char *) * (map->height + 1));
	if (!dst)
		return (NULL);
	while (i < map->height)
	{
		dst[i] = ft_strdup(map->map_mtrx[i]);
		i++;
	}
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

void	valid_path_exit(t_map *map)
{
	char	**copy_map;
	int		y;
	int		x;

	copy_map = mapcpy(map);
	if (!copy_map)
		return;
	y = 0;
	flood_fill(copy_map, map->p_ypos, map->p_xpos);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (copy_map[y][x] == 'C' || copy_map[y][x] == 'E')
			{
				write(2, "Error: Map with no valid path to collectible or exit!\n", 54);
				free(copy_map);
				return;
			}
			x++;
		}
		y++;
	}
	free(copy_map);
}
