/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:07:17 by amak              #+#    #+#             */
/*   Updated: 2023/05/25 23:48:49 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Check if there is a duplicate value in the list	*/
int	is_duplicate(t_list **lst)
{
	t_list *aux_root;
	t_list *aux_moving;
	
	aux_root = *lst;
	while (aux_root && aux_root->next)
	{
		aux_moving = aux_root->next;
		while(aux_moving)
		{
			if (aux_root->value == aux_moving->value)
				return (1);
			aux_moving = aux_moving->next;
		}
		aux_root = aux_root->next;
	}
	return (0);
}

/*	Check if the list is sorted	*/
int	is_sorted(t_list **lst)
{
	t_list	*aux;
	
	aux = *lst;
	while (aux && aux->next)
	{
		if (aux->value <= aux->next->value)
			aux = aux->next;
		else
			return (0);
	}
	return (1);
}

int	check_numbers(char *str)
{
	int		i;
	int		y;
	int		result;
	char	**array;

	i = 0;
	result = 0;
	array = ft_split(str, ' ');
	while (*array[i])
	{
		y = 0;
		if (array[i][y] == '+' || array[i][y] == '-')
			y++;
		while (array[i][y])
		{
			if (array[i][y] >= '0' && array[i][y] <= '9')
				result = 1;
			else
			{
				free (array);
				return (0);
			}
			y++;
			printf("aqui\n");
		}
		i++;
	}
	free(array);
	return (result);
}
