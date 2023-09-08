/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:45:16 by amak              #+#    #+#             */
/*   Updated: 2023/09/06 05:50:44 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	print_lst(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux != NULL)
	{
		printf("%d\n",aux->value);
		aux = aux->next;
	}
}

int main (int argc, char **argv)
{
	t_list *root_a;
	t_list *root_b;
	int		i;

	root_a = NULL;
	root_b = NULL;
	i = 1;
	
	// ft_lstadd_back(&root_a, ft_lstnew(10));
	// ft_lstadd_back(&root_a, ft_lstnew(11));
	// ft_lstadd_back(&root_a, ft_lstnew(12));
	
	// ft_lstadd_back(&root_b, ft_lstnew(20));
	// ft_lstadd_back(&root_b, ft_lstnew(21));
	// ft_lstadd_back(&root_b, ft_lstnew(22));

	if (argc > 1)
		while (i < argc)
		{
			ft_lstadd_front(&root_a, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
	
	if (is_duplicate(&root_a))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// printf("Initial Stack A: \n");
	// print_lst(root_a);
	// printf("---\n");
	// printf("Initial Stack B: \n");
	// print_lst(root_b);
	
	// printf("\n**********\n\n");
	
	// swap_single(&root_a);
	// swap_double(&root_a, &root_b);
	// push_single(&root_a, &root_b);
	// rotate_single(&root_b);
	// rotate_double(&root_a, &root_b);
	// rev_rotate_single(&root_a);
	// push_single(&root_a, &root_b);
	// rotate_single(&root_a);
	// push_single(&root_a, &root_b);
	// push_single(&root_a, &root_b);
	// rev_rotate_double(&root_a, &root_b);

	// while (ft_lstsize(root_a) > 3)
	// 	push_single(&root_a, &root_b, 'c');
	
	// printf("Movements: \n");
	if (argc <= 2)
		return (1);
	else if (argc == 3)
		move_to_top(&root_a, 'a', min_value(&root_a));
	else if (argc == 4)
		sort_three(&root_a);
	else if (argc > 4 && argc <= 6)
		sort_five(&root_a, &root_b);
	else
		sort_big(&root_a, &root_b);

	// printf("\n**********\n\n");
	// printf("Small value: %d\n", min_value(&root_a));	
	// printf("Position smal: %d\n", min_position(&root_a));
	// printf("\n**********\n\n");
	
	// move_min(&root_a, 'a');
	
	// printf("Final Stack A: \n");
	// print_lst(root_a);
	// printf("---\n");
	// // printf("Final Stack B: \n");
	// // print_lst(root_b);
		
	// printf("Is sorted: ");
	// printf("%d\n", is_sorted(&root_a));

	// printf("Cost to position 4: ");
	// printf("%d\n", calc_cost(&root_a, 4));
}



// #include "push_swap.h"

// int main (int argc, char **argv)
// {
// 	int i;

// 	i = 1;
// 	if (argc == 1)
// 	{
// 		write(1, "Error\n", 6);
// 		exit (1);
// 	}
// 	else
// 	{
// 		printf("argc = %d\n", argc);
// 		while (i < argc)
// 		{
// 			printf("i = %d\n", i);
// 			printf("teste = %d\n", check_numbers(argv[i]));
// 			if (check_numbers(argv[i]) == 0)
// 			{
// 				write(1, "Error\n", 6);
// 				exit (1);
// 			}
// 			i++;
// 		}
// 	}
// 	write(1, "OK!\n", 4);
// 	return (0);
// }
