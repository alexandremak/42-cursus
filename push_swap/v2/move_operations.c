/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:09:29 by amak              #+#    #+#             */
/*   Updated: 2023/08/28 20:41:47 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 	SA/SB/SS (swap a/b/both) : Swap the first 2 elements at the top of stack B, 
	stack B or both at the same time. Do nothing if there is only one or no
	elements. */
void	swap(t_list **a_lst, char c, t_list **b_lst)
{
	t_list	*aux_root;
	t_list	*aux_moving;

	aux_root = *a_lst;
	aux_moving = *a_lst;
	if (*a_lst != NULL)
	{
		*a_lst = aux_moving->next;
		aux_moving = aux_moving->next;
		aux_root->next = aux_moving->next;
		aux_moving->next = aux_root;
	}
	if (c == 's')
	{
		aux_root = *b_lst;
		aux_moving = *b_lst;
		if (*b_lst != NULL)
		{
			*b_lst = aux_moving->next;
			aux_moving = aux_moving->next;
			aux_root->next = aux_moving->next;
			aux_moving->next = aux_root;
		}
	}
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

/*	PA/PB (push a/b): Take the first element at the top of b/a and put it at
	the top of a/b. Do nothing if b is empty. */
void	push(t_list **lst_out, char c, t_list **lst_in)
{
	t_list	*aux;

	aux = *lst_out;
	if (*lst_out != NULL)
	{
		*lst_out = aux->next;
		ft_lstadd_front(lst_in, aux);
		if (c == 'a')
			write(1, "pa\n", 3);
		if (c == 'b')
			write(1, "pb\n", 3);
	}
}

/*	RA/RB/RR (rotate a/b/both): Shift up all elements of stack a by 1. The 
	first element becomes the last one. */
void	rotate(t_list **a_lst, char c, t_list **b_lst)
{
	t_list	*aux_root;
	t_list	*aux_moving;

	aux_root = *a_lst;
	if (aux_root != NULL && aux_root->next != NULL)
	{
		aux_moving = ft_lstlast(*a_lst);
		*a_lst = aux_root->next;
		aux_moving->next = aux_root;
		aux_root->next = NULL;
	}
	if (c == 'r')
	{
		aux_root = *b_lst;
		if (aux_root != NULL && aux_root->next != NULL)
		{
			aux_moving = ft_lstlast(*b_lst);
			*b_lst = aux_root->next;
			aux_moving->next = aux_root;
			aux_root->next = NULL;
		}
	}
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

/*	RRA/RRB/RRR (reverse rotate a/b/both): Shift down all elements of stack a
	by 1. The last element becomes the first one. */
void	rev_rotate(t_list **a_lst, char c, t_list **b_lst)
{
	t_list	*aux_root;
	t_list	*aux_moving;

	aux_root = *a_lst;
	aux_moving = *a_lst;
	if (aux_root != NULL && aux_root->next != NULL)
	{
		while (aux_moving->next->next != NULL)
			aux_moving = aux_moving->next;
		*a_lst = aux_moving->next;
		aux_moving->next->next = aux_root;
		aux_moving->next = NULL;
	}
	if (c == 'r')
	{
		aux_root = *b_lst;
		aux_moving = *b_lst;
		if (aux_root != NULL && aux_root->next != NULL)
		{
			while (aux_moving->next->next != NULL)
				aux_moving = aux_moving->next;
		*b_lst = aux_moving->next;
		aux_moving->next->next = aux_root;
		aux_moving->next = NULL;
		}
	}
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}
