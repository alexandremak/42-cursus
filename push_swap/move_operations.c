/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:09:29 by amak              #+#    #+#             */
/*   Updated: 2023/05/18 23:41:06 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 	SA/SB (swap a/b) : Swap the first 2 elements at the top of stack a. Do
	nothing if there is only one or no elements. */
void	swap_single(t_list **lst, char c)
{
	t_list *aux_root;
	t_list *aux_moving;

	aux_root = *lst;
	aux_moving = *lst;
	if (*lst != NULL)
	{
		*lst = aux_moving->next;
		aux_moving = aux_moving->next;
		aux_root->next = aux_moving->next;
		aux_moving->next = aux_root;
		if (c =='a')
			write(1, "sa\n", 3);
		if (c =='b')
			write(1, "sb\n", 3);
	}
}

/*	SS : SA and SB at the same time. */
void	swap_double(t_list **a_lst, t_list **b_lst)
{
	swap_single(a_lst, 's');
	swap_single(b_lst, 's');
	write(1, "ss\n", 3);
}

/*	PA/PB (push a/b): Take the first element at the top of b/a and put it at
	the top of a/b. Do nothing if b is empty. */
void	push_single(t_list **lst_out, t_list **lst_in, char c)
{
	t_list *aux;

	aux = *lst_out;
	if (*lst_out != NULL)
	{
		*lst_out = aux->next;
		ft_lstadd_front(lst_in, aux);
		if (c =='a')
			write(1, "pa\n", 3);
		if (c =='b')
			write(1, "pb\n", 3);
	}
}

/*	RA/RB (rotate a/b): Shift up all elements of stack a by 1. The first
	element becomes the last one. */
void	rotate_single(t_list **lst, char c)
{
	t_list *aux_root;
	t_list *aux_moving;

	aux_root = *lst;
	if (aux_root != NULL && aux_root->next != NULL)
	{
		aux_moving = ft_lstlast(*lst);
		*lst = aux_root->next;
		aux_moving->next = aux_root;
		aux_root->next = NULL;
		if (c =='a')
			write(1, "ra\n", 3);
		if (c =='b')
			write(1, "rb\n", 3);
	}
}

/*	RR : RA and RB at t	he same time. */
void	rotate_double(t_list **a_lst, t_list **b_lst)
{
	rotate_single(a_lst, 's');
	rotate_single(b_lst, 's');
	write(1, "rr\n", 3);
}

/*	RRA/RRB (reverse rotate a/b): Shift down all elements of stack a by 1.
The last element becomes the first one. */
void	rev_rotate_single(t_list **lst, char c)
{
	t_list *aux_root;
	t_list *aux_moving;

	aux_root = *lst;
	aux_moving = *lst;
	if (aux_root != NULL && aux_root->next != NULL)
	{
		while (aux_moving->next->next != NULL)
			aux_moving = aux_moving->next;
		*lst = aux_moving->next;
		aux_moving->next->next = aux_root;
		aux_moving->next = NULL;
		if (c =='a')
			write(1, "rra\n", 4);
		if (c =='b')
			write(1, "rrb\n", 4);
	}
}

/*	RRR : rra and rrb at the same time. */
void	rev_rotate_double(t_list **a_lst, t_list **b_lst)
{
	rev_rotate_single(a_lst, 's');
	rev_rotate_single(b_lst, 's');
	write(1, "rrr\n", 3);
}
