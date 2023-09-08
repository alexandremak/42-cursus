/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 03:14:43 by amak              #+#    #+#             */
/*   Updated: 2023/09/06 06:26:47 by amak             ###   ########.fr       */
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
	while (ft_lstsize(*stack_a) > 5)
	{
		move_to_top(stack_a, min_value(stack_a));
		pb(stack_a, stack_b);
	}
	sort_five(stack_a, stack_b);
	while (ft_lstsize(*stack_b) > 0)
		pa(stack_b, stack_a);
}
