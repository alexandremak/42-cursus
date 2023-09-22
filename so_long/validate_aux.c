/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:26:04 by amak              #+#    #+#             */
/*   Updated: 2023/09/22 10:12:10 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_char(char c)
{
	if (ft_strchr("01PEC", c))
		return (1);
	else
		return (0);
}

int	load_component(t_map *map, int y, int x)
{
	if (map->map_mtrx[y][x] == 'C')
		map->collects++;
	if (map->map_mtrx[y][x] == 'P')
	{
		if (map->p_ypos != 0)
		{
			write(2, "Error: Map with more than one player position!\n", 47);
			return (0);
		}
		map->p_ypos = y;
		map->p_xpos = x;
	}
	if (map->map_mtrx[y][x] == 'E')
	{
		if (map->e_ypos != 0)
		{
			write(2, "Error: Map with more than one exit!\n", 36);
			return (0);
		}
		map->e_ypos = y;
		map->e_xpos = x;
	}
	return (1);
}

int	must_contain(t_map *map)
{
	int result;

	result = 1;
	if (map->collects == 0)
	{
		write (2, "Error: Map with no collectibles\n", 32);
		result = 0;
	}
	if (map->p_ypos == 0)
	{
		write (2, "Error: Map with no player!\n", 27);
		result = 0;
	}
	if (map->e_ypos == 0)
	{
		write (2, "Error: Map with no exit!\n", 25);
		result = 0;
	}
	return (result);
}

void	free_map(char **map)
{
	while (*map)
	{
		free(*map);
		map++;
	}
	free (map);
}