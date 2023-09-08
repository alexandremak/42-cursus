/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:03:32 by amak              #+#    #+#             */
/*   Updated: 2023/09/06 03:09:23 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Check if a string is a valid number (with or without signal + or - in the
	begining and returns true or false value */
int		is_valid_number(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == 0)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == 0)
		return (1);
	else
		return (0);
}

/*	Check if the parameters are valid integer numbers and returns true or false
	value */
int 	is_valid_input(int count, char **values)
{
	int	i;
	char **split_arg;

	i = 1;
	while (i < count)
	{
		split_arg = ft_split(values[i], ' ');
		while (*split_arg)
		{
			if (!is_valid_number(*split_arg))
				return (0);
			if (ft_atoi(*split_arg) < INT_MIN || ft_atoi(*split_arg) > INT_MAX)
				return(0);
			split_arg++;
		}
		i++;
	}
	return (1);
}

/*	Displays "Error" if the parameters are not valid integer numbers.
	If all are valid, it loads the values to a list so that the first argument
	be at the top of the stack meaning that it will be adding the values to the
	back of the stack */
void	load_input(int argc, char **argv, t_list **stack)
{
	int i;
	char **split_arg;
	
	i = 1;
	if (!is_valid_input(argc, argv))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	else
	{
		while (i < argc)
		{
			split_arg = ft_split(argv[i], ' ');
			while (*split_arg)
			{
				ft_lstadd_back(stack, ft_lstnew(ft_atoi(*split_arg)));
				split_arg++;
			}
			i++;
		}
	}	
}
