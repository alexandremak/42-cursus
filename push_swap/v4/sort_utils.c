/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 03:28:15 by amak              #+#    #+#             */
/*   Updated: 2023/09/08 02:13:56 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Returns the maximum value of the list */
int	max_value(t_list **stack)
{
	t_list	*aux;
	int		max;

	aux = *stack;
	max = aux->value;
	while (aux->next)
	{
		aux = aux->next;
		if (max < aux->value)
			max = aux->value;
	}
	return (max);
}

/*	Returns the minimum value of the list */
int	min_value(t_list **stack)
{
	t_list	*aux;
	int		min;

	aux = *stack;
	min = aux->value;
	while (aux->next)
	{
		aux = aux->next;
		if (min > aux->value)
			min = aux->value;
	}
	return (min);
}

/*	Returns the position of a value in the list, as the first position is 1,
	if the value doen't exists return 0 */
int	value_position(t_list **stack, int value)
{
	t_list	*aux;
	int		i;
	int		position;

	aux = *stack;
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

void	move_to_top(t_list **stack, int value)
{
	int	middle;
	int	pos;

	middle = (ft_lstsize(*stack) / 2) + 1;
	pos = value_position(stack, value);
	if (pos <= middle)
	{
		while (pos > 1)
		{
			ra(stack);
			pos--;
		}
	}
	else
	{
		while (pos <= ft_lstsize(*stack))
		{
			rra(stack);
			pos++;
		}
	}
}

void	fill_position(t_list **stack)
{
	t_list	*base;
	t_list	*aux;
	int		index;

	base = *stack;
	while (base)
	{
		aux = *stack;
		index = 0;
		while (aux)
		{
			if (base->value > aux->value)
				index++;
			aux = aux->next;
		}
		base->position = index;
		base = base->next;
	}
}
