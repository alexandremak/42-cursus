/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:09:29 by amak              #+#    #+#             */
/*   Updated: 2023/09/06 06:09:06 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 	SWAP: Swap the first 2 elements at the top of stack. Do nothing if there is
	only one or no elements. */
void	swap(t_list **stack)
{
	t_list	*aux_root;
	t_list	*aux_moving;

	aux_root = *stack;
	aux_moving = *stack;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = aux_moving->next;
		aux_moving = aux_moving->next;
		aux_root->next = aux_moving->next;
		aux_moving->next = aux_root;
	}
}

/*	PUSH: Take the first element at the top of stack and put it a the top of
	other. Do nothing if the stack is empty. */
void	push(t_list **stack_out, t_list **stack_in)
{
	t_list	*aux;

	aux = *stack_out;
	if (*stack_out != NULL)
	{
		*stack_out = aux->next;
		ft_lstadd_front(stack_in, aux);
	}
}

/*	ROTATE: Shift up all elements of stack a by 1. The first element becomes
	the last one. */
void	rotate(t_list **stack)
{
	t_list	*aux_root;
	t_list	*aux_moving;

	aux_root = *stack;
	if (aux_root != NULL && aux_root->next != NULL)
	{
		aux_moving = ft_lstlast(*stack);
		*stack= aux_root->next;
		aux_moving->next = aux_root;
		aux_root->next = NULL;
	}

}

/*	REVERSE ROTATE: Shift down all elements of stack a by 1. The last element
	becomes the first one. */
void	rev_rotate(t_list **stack)
{
	t_list	*aux_root;
	t_list	*aux_moving;

	aux_root = *stack;
	aux_moving = *stack;
	if (aux_root != NULL && aux_root->next != NULL)
	{
		while (aux_moving->next->next != NULL)
			aux_moving = aux_moving->next;
		*stack = aux_moving->next;
		aux_moving->next->next = aux_root;
		aux_moving->next = NULL;
	}
}
