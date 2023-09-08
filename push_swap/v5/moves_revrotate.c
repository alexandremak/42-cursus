/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:22:10 by amak              #+#    #+#             */
/*   Updated: 2023/09/08 02:23:01 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack)
{
	if (*stack || (*stack)->next)
	{
		rev_rotate(stack);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack)
{
	if (*stack || (*stack)->next)
	{
		rev_rotate(stack);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a || (*stack_a)->next)
	{
		if (*stack_b || (*stack_b)->next)
		{
			rev_rotate(stack_a);
			rev_rotate(stack_b);
			write(1, "rrr\n", 4);
		}
	}
}
