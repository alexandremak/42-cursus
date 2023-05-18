/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:00:40 by amak              #+#    #+#             */
/*   Updated: 2023/05/18 22:01:02 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		result;

	result = 0;
	aux = lst;
	while (aux != NULL)
	{
		aux = aux->next;
		result++;
	}
	return (result);
}
