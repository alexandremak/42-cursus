/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:14:43 by amak              #+#    #+#             */
/*   Updated: 2023/05/25 23:56:40 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Returns the minimum value of the list */
int	min_value(t_list **lst)
{
	t_list	*aux;
	int		min;

	aux = *lst;
	min = aux->value;
	while (aux->next)
	{
		aux = aux->next;
		if (min > aux->value)
			min = aux->value;
	}
	return (min);
}

/*	Returns the maximum value of the list */
int	max_value(t_list **lst)
{
	t_list	*aux;
	int		max;

	aux = *lst;
	max = aux->value;
	while (aux->next)
	{
		aux = aux->next;
		if (max < aux->value)
			max = aux->value;
	}
	return (max);
}

/*	Returns the position of a value in of the list, as the first position is 1 */
int	value_position(t_list **lst, int value)
{
	t_list	*aux;
	int		i;
	int		position;

	aux = *lst;
	i = 1;
	position = 0;
	while (aux)
	{
		if (aux->value == value)
		{
			position = i;
			return (position);
		}
		aux = aux->next;
		i++;
	}
	return (position);
}

/*	Returns the number of rotate or reverse rotate movements needed for a given
	position to reach the first the list */
int	calc_cost(t_list **lst, int pos)
{
	int	middle;

	middle = (ft_lstsize(*lst) / 2) + 1;
	if (pos <= middle)
		return (pos - 1);
	else
		return (ft_lstsize(*lst) - pos + 1);
}
