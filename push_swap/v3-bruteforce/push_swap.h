/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:04:36 by amak              #+#    #+#             */
/*   Updated: 2023/09/06 04:39:44 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/* STRUCTURES: */
typedef struct s_list
{
	int				value;
	struct s_list	*next;
	int				position;
}	t_list;

/* LIBFT FUNCTIONS: */
long long	ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content);
int			ft_lstsize(t_list *lst);
char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);

/* BASIC MOVES FUNCTIONS: */
void		swap(t_list **stack);
void		push(t_list **stack_out, t_list **stack_in);
void		rotate(t_list **stack);
void		rev_rotate(t_list **stack);

/* SWAP MOVES FUNCTIONS: */
void		sa(t_list **stack);
void		sb(t_list **stack);
void		ss(t_list **stack_a, t_list **stack_b);

/* PUSH MOVES FUNCTIONS: */
void		pa(t_list **stack_out, t_list **stack_in);
void		pb(t_list **stack_out, t_list **stack_in);

/* ROTATE MOVES FUNCTIONS: */
void		ra(t_list **stack);
void		rb(t_list **stack);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack);
void		rrb(t_list **stack);
void		rrr(t_list **stack_a, t_list **stack_b);

/* VALIDATE INPUT FUNCTIONS: */
int			is_valid_number(char *str);
int 		is_valid_input(int count, char **values);
void		load_input(int argc, char **argv, t_list **list);

/* VALIDATE LIST FUNCTIONS: */
void		free_list(t_list **stack);
int			is_duplicate(t_list **stack);
int			is_sorted(t_list **stack);
void		check_list(t_list **stack);

/* SORT UTILITIES FUNCTIONS: */
int			max_value(t_list **stack);
int			min_value(t_list **stack);
int			value_position(t_list **stack, int value);
void		move_to_top(t_list **stack, int value);
void		fill_position(t_list **stack);


/* SORT FUNCTIONS: */
void		sort_three(t_list **stack);
void		sort_five(t_list **stack_a, t_list **stack_b);
void		sort_radix(t_list **stack_a, t_list **stack_b);

#endif