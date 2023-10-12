/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:31:32 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 22:42:28 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	Recursive function that reads the map file data and loads to the map
	matrix of the map structure */
void	load_map(t_windows *window, int fd, int count_line)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		load_map(window, fd, count_line + 1);
	else if (count_line > 0)
	{
		window->map.height = count_line;
		window->map.mtrx = malloc(sizeof(char *) * (count_line + 1));
	}
	if (window->map.mtrx)
		window->map.mtrx[count_line] = line;
}

/*	Checks if the map is an rectagle, the width is the length of the first row
	but keeping in mind that the '\n' of the end of the line is considered for
	checking the length */
int	is_rectangle(t_windows *window)
{
	size_t	width;
	int		i;

	i = 0;
	while (window->map.mtrx[i])
	{
		width = ft_strlen(window->map.mtrx[i]);
		if (window->map.mtrx[i][width - 1] == '\n')
		{
			if (width != ft_strlen(window->map.mtrx[0]))
				return (0);
		}
		else
		{
			if (width != (ft_strlen(window->map.mtrx[0]) - 1))
				return (0);
		}
		i++;
	}
	window->map.width = ft_strlen(window->map.mtrx[0]) - 1;
	return (1);
}

/*	Checks if the map is surrounded by a wall, ckecking that the first and 
	last row only has '1' chars and the other rows begins and ends with 
	'1' */
int	wall_ok(t_map *map)
{
	int	i;

	i = 0;
	while (map->mtrx[0][i] && i <= map->width - 1)
	{
		if (map->mtrx[0][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i <= (map->height - 2))
	{
		if ((map->mtrx[i][0] != '1') || (map->mtrx[i][map->width - 1] != '1'))
			return (0);
		i++;
	}
	i = 0;
	while (map->mtrx[map->height - 1][i] && i <= map->width - 1)
	{
		if (map->mtrx[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

/*	Check in a map if all the components are valid, after loading each 
	components checks if all mandatory are loaded */
int	valid_components(t_windows *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < window->map.height)
	{
		x = 0;
		while (x < window->map.width)
		{
			if (!valid_char(window->map.mtrx[y][x]))
				return (0);
			if (!load_component(window, y, x))
				return (0);
			x++;
		}
		y++;
	}
	if (!must_contain(window))
		return (0);
	return (1);
}

/*	This is the main function to validate a map loaded from file */
void	check_map(int fd, t_windows *window)
{
	load_map(window, fd, 0);
	close(fd);
	if (!window->map.mtrx)
	{
		write(2, "Error: First line of Map file is empty!\n", 40);
		close_window(window);
	}
	if (!is_rectangle(window))
	{
		write(2, "Error: Map dimension is not a rectangle!\n", 41);
		close_window(window);
	}
	if (!wall_ok(&window->map))
	{
		write(2, "Error: Map is not closed/surrounded by walls!\n", 46);
		close_window(window);
	}
	if (!valid_components(window))
	{
		write(2, "Error: Map with incorrect components!\n", 38);
		close_window(window);
	}
}
