/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:31:32 by amak              #+#    #+#             */
/*   Updated: 2023/09/22 12:31:21 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_map *map, int fd, int count_line)
{
	char *line;

	line = get_next_line(fd);
	if (line)
		load_map(map, fd, count_line + 1);
	else if (count_line > 0)
	{
		map->height = count_line;
		map->map_mtrx = malloc(sizeof(char *) * (count_line + 1));
	}
	if (map->map_mtrx)
		map->map_mtrx[count_line] = line;
}

int 	is_rectangle(t_map *map)
{
	size_t	width;
	int		i;
	
	i = 0;
	while(map->map_mtrx[i])
	{
		width = ft_strlen(map->map_mtrx[i]);
		if (i < (map->height - 1))
		{
			if (width != ft_strlen(map->map_mtrx[0]))
				return (0);
		}
		else
		{
			if (width != (ft_strlen(map->map_mtrx[0]) - 1))
				return (0);
		}
		i++;
	}
	map->width = ft_strlen(map->map_mtrx[0]) - 1;
	return (1);
}

int		wall_ok(t_map *map)
{
	int	i;
	int	p_height;
	int	p_width;

	i = 0;
	p_height = map->height - 1;
	p_width = map->width - 1;
	while (map->map_mtrx[0][i] && i <= p_width)
	{
		if(map->map_mtrx[0][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i <= (p_height - 1))
	{
		if ((map->map_mtrx[i][0] != '1') || (map->map_mtrx[i][p_width] != '1'))
			return (0);
		i++;
	}
	i = 0;
	while (map->map_mtrx[p_height][i] && i <= p_width)
	{
		if(map->map_mtrx[p_height][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_components(t_map *map)
{
	int	x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			
			if (!valid_char(map->map_mtrx[y][x]))
				return (0);
			if (!load_component(map, y, x))
				return (0);
			x++;
		}
		y++;
	}
	if (!must_contain(map))
		return (0);
	return (1);
}

void	check_map(int fd, t_map *map)
{
	
	load_map(map, fd, 0);
	if (!map->map_mtrx[0])
	{
		write(2, "Error: First line of Map file is empty!\n", 40);
		return;
	}
	if (!is_rectangle(map))
	{
		write(2, "Error: Map dimension is not a rectangle!\n", 41);
		return;
	}
	if (!wall_ok(map))
	{
		write(2, "Error: Map is not closed/surrounded by walls!\n", 46);
		return;
	}
	if (!valid_components(map))
	{
		write(2, "Error: Map with incorrect components!\n", 38);
		return;
	}
}
