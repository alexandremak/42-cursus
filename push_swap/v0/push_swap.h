/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:04:36 by amak              #+#    #+#             */
/*   Updated: 2023/05/21 15:44:35 by amak             ###   ########.fr       */
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
void	swap_single(t_list **lst, char c);
void	swap_double(t_list **a_lst, t_list **b_lst);
void	push_single(t_list **lst_out, t_list **lst_in, char c);
void	rotate_single(t_list **lst, char c);
void	rotate_double(t_list **a_lst, t_list **b_lst);
void	rev_rotate_single(t_list **lst, char c);
void	rev_rotate_double(t_list **a_lst, t_list **b_lst);

/* UTILS FUNCTIONS: */
int		check_numbers(char *str);

/* SORT FUNCTION: */
void	sort_three(t_list **lst);
void	sort_five(t_list **a_lst, t_list **b_lst);
void	sort_big(t_list **a_lst, t_list **b_lst);

/* SORT UTILS: */
int		min_value(t_list **lst);
int		min_position(t_list **lst);
void	move_min(t_list **lst, char c);

#endif