/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:31:32 by amak              #+#    #+#             */
/*   Updated: 2023/09/15 19:19:27 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_dimension(int fd)
{
	char	*x_axis;
	int		x_length;

	x_axis = get_next_line(fd);
	if (!x_axis)
	{
		write(2, "Error: First line of Map file is empty!\n", 40);
	}
	else
	{
		x_length = ft_strlen(x_axis);
		printf("length = %d \n", x_length);
	}
}
