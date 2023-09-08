/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:45:16 by amak              #+#    #+#             */
/*   Updated: 2023/09/02 11:02:02 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_list *a;
	// t_list *b;

	a = NULL;
	// b = NULL;
	load_values(argc, argv, a);
	while (a)
		{
			write(1, "b", 1);
			printf("%d", a->value);
			a = a->next;
		}
	// if (ft_lstsize(a) <= 3)
	// 	sort_three(&a);
	// else
	// 	if (ft_lstsize(a) <= 5)
	// 		sort_five(&a, &b);
	return (0);
}


// valgrind --leak-check=full --show-leak-kinds=all ./push_swap "1234 5678" 