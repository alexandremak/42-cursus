/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:53:35 by amak              #+#    #+#             */
/*   Updated: 2023/09/08 04:23:49 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	load_input(argc, argv, &stack_a);
	fill_position(&stack_a);
	check_list(&stack_a);
	if (ft_lstsize(stack_a) <= 3)
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) <= 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_radix(&stack_a, &stack_b);
	check_list(&stack_a);
}

// valgrind --leak-check=full --show-leak-kinds=all
// ./push_swap 5 4 3 10 8 7 6 41 31 "55 98 324 -12"