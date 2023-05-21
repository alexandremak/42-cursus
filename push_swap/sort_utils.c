/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:14:43 by amak              #+#    #+#             */
/*   Updated: 2023/05/20 23:16:37 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min_value(t_list **lst)
{
	t_list	*aux;
	int		min;
	
	aux = *lst;
	min = aux->value;
	while (aux->next)
	{
		aux = aux->next;
		if (min > aux->value)
			min = aux->value;
	}
	return (min);
}

int		min_position(t_list **lst)
{
	t_list	*aux;
	int		min;
	int		i;
	int		position;
	
	aux = *lst;
	min = aux->value;
	position = 1;
	i = 1;
	while (aux->next)
	{
		aux = aux->next;
		i++;
		if (min > aux->value)
		{
			min = aux->value;
			position = i;
		}
	}
	return (position);
}

void	move_min(t_list **lst, char c)
{
	int	middle;
	int pos;
	
	middle = (ft_lstsize(*lst) / 2) + 1;
	pos = min_position(lst);
	
	if (pos <= middle)
		while (pos > 1)
		{
			rotate_single(lst, c);
			pos--;
		}
	else
		while (pos <= ft_lstsize(*lst))
		{
			rev_rotate_single(lst, c);
			pos++;
		}
}