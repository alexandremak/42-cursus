/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:04:36 by amak              #+#    #+#             */
/*   Updated: 2023/09/02 10:56:39 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* STRUCTURES: */
typedef struct s_list
{
	int				value;
	int				position;
	struct s_list	*next;
}	t_list;

/* LIBFT FUNCTIONS: */
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

/* MOVE OPERATIONS FUNCTIONS: */
void	swap(t_list **a_lst, char c, t_list **b_lst);
void	push(t_list **lst_out, char c, t_list **lst_in);
void	rotate(t_list **a_lst, char c, t_list **b_lst);
void	rev_rotate(t_list **a_lst, char c, t_list **b_lst);

/* UTILS FUNCTIONS: */
int		is_duplicate(t_list **lst);
int		is_sorted(t_list **lst);
int		check_numbers(char *str);
int		contains(int number, t_list *list);

/* SORT FUNCTION: */
void	move_to_top(t_list **lst, char c, int value);
void	sort_three(t_list **lst);
void	sort_five(t_list **a_lst, t_list **b_lst);
void	sort_big(t_list **a_lst, t_list **b_lst);

/* SORT UTILS: */
int		min_value(t_list **lst);
int		max_value(t_list **lst);
int		value_position(t_list **lst, int value);

/* INPUT VALIDATION FUNCTIONS: */
int		is_valid_char(char c);
int		is_valid_number(char *str);
int 	is_valid_input(int count, char **values);
void	load_values(int argc, char **argv, t_list *list);

#endif