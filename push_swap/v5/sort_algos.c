/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 03:14:43 by amak              #+#    #+#             */
/*   Updated: 2023/09/08 03:53:40 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	int	first;
	int	second;

	first = (*stack)->value;
	second = (*stack)->next->value;
	if (first == max_value(stack))
		ra(stack);
	else if (second == max_value(stack))
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	move_to_top(stack_a, min_value(stack_a));
	if (!is_sorted(stack_a))
	{
		pb(stack_a, stack_b);
		if (ft_lstsize(*stack_a) == 4)
		{
			move_to_top(stack_a, min_value(stack_a));
			if (!is_sorted(stack_a))
				pb(stack_a, stack_b);
		}
		sort_three(stack_a);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
	}
}

void	sort_radix(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->position) >> i) & 1) 
				ra(stack_a);
			else 
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		i++;
	}
}
