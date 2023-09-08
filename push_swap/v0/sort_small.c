/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:14:11 by amak              #+#    #+#             */
/*   Updated: 2023/05/21 18:31:25 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	biggest(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (a > b && c > a)
		return (c);
	else if (a < b && c < b)
		return (b);
	else if (a < b && b < c)
		return (c);
	else
		return (b);
}

void	sort_three(t_list **lst)
{
	int	first;
	int	second;
	int	third;

	first = (*lst)->value;
	second = (*lst)->next->value;
	third = (*lst)->next->next->value;
	if (first == biggest(first, second, third))
		rotate_single(lst, 'a');
	else if (second == biggest(first, second, third))
		rev_rotate_single(lst, 'a');
	if ((*lst)->value > (*lst)->next->value)
		swap_single(lst, 'a');
}

void	sort_five(t_list **a_lst, t_list **b_lst)
{
	move_min(a_lst, 'a');
	push_single(a_lst, b_lst, 'b');
	if (ft_lstsize(*a_lst) == 4)
	{
		move_min(a_lst, 'a');
		push_single(a_lst, b_lst, 'b');
	}
	sort_three(a_lst);
	push_single(b_lst, a_lst, 'a');
	push_single(b_lst, a_lst, 'a');
}
