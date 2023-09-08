/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:40:20 by amak              #+#    #+#             */
/*   Updated: 2023/09/08 02:21:43 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack)
{
	if (*stack || (*stack)->next)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack)
{
	if (*stack || (*stack)->next)
	{
		rotate(stack);
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a || (*stack_a)->next)
	{
		if (*stack_b || (*stack_b)->next)
		{
			rotate(stack_a);
			rotate(stack_b);
			write(1, "rr\n", 3);
		}
	}
}
