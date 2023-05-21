/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:35:10 by amak              #+#    #+#             */
/*   Updated: 2023/05/21 15:49:34 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_list **a_lst, t_list **b_lst)
{
	while (ft_lstsize(*a_lst) > 5)
	{
		move_min(a_lst, 'a');
		push_single(a_lst, b_lst, 'b');
	}
	sort_five(a_lst, b_lst);
	while (ft_lstsize(*b_lst) > 0)
		push_single(b_lst, a_lst, 'a');
}