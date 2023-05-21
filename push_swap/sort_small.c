/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:14:11 by amak              #+#    #+#             */
/*   Updated: 2023/05/20 23:41:36 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	t_list *aux;
	
	aux = *lst;
	if (aux->value > aux->next->value)
	{
		if (aux->next->value > aux->next->next->value)
		{
			swap_single(lst, 'a');
			rev_rotate_single(lst, 'a');	
		} 
		else
			if (aux->value > aux->next->next->value)
				rev_rotate_single(lst, 'a');
			else
				swap_single(lst, 'a');
	}
	else
		if (aux->next->value > aux->next->next->value)
		{
			if (aux->value > aux->next->next->value)
				rev_rotate_single(lst, 'a');
			else
			{
				swap_single(lst, 'a');
				rotate_single(lst, 'a');
			}
		}
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