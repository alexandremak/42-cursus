/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:07:17 by amak              #+#    #+#             */
/*   Updated: 2023/05/09 21:17:05 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(char *str)
{
	int		i;
	int		y;
	int		result;
	char	**array;
	
	i = 0;
	result = 0;
	array = ft_split(str, ' ');
	while (*array[i])
	{
		y = 0;
		if (array[i][y] == '+' || array[i][y] == '-')
			y++;
		while (array[i][y])
		{
			if (array[i][y] >= '0' && array[i][y] <= '9')
				result = 1;
			else
			{
				free (array);
				return (0);
			}
			y++;
			printf("aqui\n");
		}
		i++;
	}
	free(array);
	return (result);
}