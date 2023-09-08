/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:24:32 by amak              #+#    #+#             */
/*   Updated: 2023/09/06 06:17:48 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack)
{
	if (*stack && (*stack)->next)
		swap(stack);
		write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	if (*stack && (*stack)->next)
		swap(stack);
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		if (*stack_b && (*stack_b)->next)
		{
			swap(stack_a);
			swap(stack_b);
			write(1, "ss\n", 3);
		}
}