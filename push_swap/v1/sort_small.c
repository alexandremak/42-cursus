/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:14:11 by amak              #+#    #+#             */
/*   Updated: 2023/05/26 00:00:33 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_list **lst, char c, int value)
{
	int	middle;
	int	pos;

	middle = (ft_lstsize(*lst) / 2) + 1;
	pos = value_position(lst, value);
	if (pos <= middle)
		while (pos > 1 )
		{
			rotate(lst, c, NULL);
			pos--;
		}
	else
		while (pos <= ft_lstsize(*lst))
		{
			rev_rotate(lst, c, NULL);
			pos++;
		}
}

void	sort_three(t_list **lst)
{
	int	first;
	int	second;

	first = (*lst)->value;
	second = (*lst)->next->value;
	if (first == max_value(lst))
		rotate(lst, 'a', NULL);
	else if (second == max_value(lst))
		rev_rotate(lst, 'a', NULL);
	if ((*lst)->value > (*lst)->next->value)
		swap(lst, 'a', NULL);
}

void	sort_five(t_list **a_lst, t_list **b_lst)
{
	move_to_top(a_lst, 'a', min_value(a_lst));
	if (!is_sorted(a_lst))
	{
		push(a_lst, 'b', b_lst);
		if (ft_lstsize(*a_lst) == 4)
		{
			move_to_top(a_lst, 'a', min_value(a_lst));
			if (!is_sorted(a_lst))
				push(a_lst, 'b', b_lst);
		}
		sort_three(a_lst);
		push(b_lst, 'a', a_lst);
		push(b_lst, 'a', a_lst);
	}
}
