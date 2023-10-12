/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:26:04 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 03:15:02 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	Checks if a char is a valid from the game char list */
int	valid_char(char c)
{
	if (ft_strchr("01PEC", c))
		return (1);
	else
		return (0);
}

/*	Checks a char from map and load the component data in the map struct */
int	load_component(t_windows *window, int y, int x)
{
	if (window->map.mtrx[y][x] == 'C')
		window->map.collects++;
	if (window->map.mtrx[y][x] == 'P')
	{
		if (window->map.ply_y != 0)
		{
			write(2, "Error: Map with more than one player position!\n", 47);
			return (0);
		}
		window->map.ply_y = y;
		window->map.ply_x = x;
	}
	if (window->map.mtrx[y][x] == 'E')
	{
		if (window->map.ext_y != 0)
		{
			write(2, "Error: Map with more than one exit!\n", 36);
			return (0);
		}
		window->map.ext_y = y;
		window->map.ext_x = x;
	}
	return (1);
}

/*	Validate if the map has the correct components */
int	must_contain(t_windows *window)
{
	int	result;

	result = 1;
	if (window->map.collects == 0)
	{
		write (2, "Error: Map with no collectibles\n", 32);
		result = 0;
	}
	if (window->map.ply_y == 0)
	{
		write (2, "Error: Map with no player!\n", 27);
		result = 0;
	}
	if (window->map.ext_y == 0)
	{
		write (2, "Error: Map with no exit!\n", 25);
		result = 0;
	}
	return (result);
}
