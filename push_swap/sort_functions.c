/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:14:11 by amak              #+#    #+#             */
/*   Updated: 2023/05/18 23:41:55 by amak             ###   ########.fr       */
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