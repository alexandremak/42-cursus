/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:32:47 by amak              #+#    #+#             */
/*   Updated: 2023/09/08 02:09:56 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_out, t_list **stack_in)
{
	if (*stack_out)
	{
		push(stack_out, stack_in);
		write(1, "pa\n", 3);
	}
}

void	pb(t_list **stack_out, t_list **stack_in)
{
	if (*stack_out)
	{
		push(stack_out, stack_in);
		write(1, "pb\n", 3);
	}
}
