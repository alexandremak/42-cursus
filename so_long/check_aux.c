/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:26:04 by amak              #+#    #+#             */
/*   Updated: 2023/10/09 20:41:39 by amak             ###   ########.fr       */
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

int	load_component(t_windows *window, int y, int x)
{
	if (window->map.map_mtrx[y][x] == 'C')
		window->map.collects++;
	if (window->map.map_mtrx[y][x] == 'P')
	{
		if (window->map.p_ypos != 0)
		{
			write(2, "Error: Map with more than one player position!\n", 47);
			return (0);
		}
		window->map.p_ypos = y;
		window->map.p_xpos = x;
	}
	if (window->map.map_mtrx[y][x] == 'E')
	{
		if (window->map.e_ypos != 0)
		{
			write(2, "Error: Map with more than one exit!\n", 36);
			return (0);
		}
		window->map.e_ypos = y;
		window->map.e_xpos = x;
	}
	return (1);
}

int	must_contain(t_windows *window)
{
	int	result;

	result = 1;
	if (window->map.collects == 0)
	{
		write (2, "Error: Map with no collectibles\n", 32);
		result = 0;
	}
	if (window->map.p_ypos == 0)
	{
		write (2, "Error: Map with no player!\n", 27);
		result = 0;
	}
	if (window->map.e_ypos == 0)
	{
		write (2, "Error: Map with no exit!\n", 25);
		result = 0;
	}
	return (result);
}
