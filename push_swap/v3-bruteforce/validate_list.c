/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:14:15 by amak              #+#    #+#             */
/*   Updated: 2023/09/06 03:58:48 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Frees a the content of a list from memory  */
void	free_list(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	exit(0);
}

/*	Check if there are duplicate values in a list and returns true or false
	value */
int		is_duplicate(t_list **stack)
{
	t_list	*base;
	t_list	*aux;

	base = *stack;
	while (base && base->next)
	{
		aux = base->next;
		while (aux)
		{
			if (base->value == aux->value)
				return (1);
			aux = aux->next;
		}
		base = base->next;
	}
	return (0);
}

/*	Check if the values in a list are sorted from the smallest at the top to
	the biggest at the bottom and returns true or false value */
int		is_sorted(t_list **stack)
{
	t_list	*aux;
	
	aux = *stack;
	while (aux && aux->next)
	{
		if (aux->value < (aux->next)->value)
			aux = aux->next;
		else
			return (0);
	}
	return (1);
}

void	check_list(t_list **stack)
{
	if (is_duplicate(stack))
	{
		write(2, "Error\n",6);
		free_list(stack);
	}
	if (is_sorted(stack))
		free_list(stack);
}