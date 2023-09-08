/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:35:10 by amak              #+#    #+#             */
/*   Updated: 2023/05/26 00:16:26 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_list **a_lst, t_list **b_lst)
{
	while (ft_lstsize(*a_lst) > 5)
	{
		move_to_top(a_lst, 'a', min_value(a_lst));
		push(a_lst, 'b', b_lst);
	}
	sort_five(a_lst, b_lst);
	while (ft_lstsize(*b_lst) > 0)
		push(b_lst, 'a', a_lst);
}
