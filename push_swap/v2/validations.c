/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:41:58 by amak              #+#    #+#             */
/*   Updated: 2023/09/02 10:56:32 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_char(char c)
{
	if ((c >= 48 && c <= 57) || (c == 43) || (c == 45))
		return 1;
	else if (((c >= 9) && (c <= 13)) || c == 32)
		return 1;
	else
		return 0;
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_valid_char(str[i]))
			return 0;
	i++;
	}
	return 1;
}

int is_valid_input(int count, char **values)
{
	int	i;
	char **split_arg;

	i = 1;
	if (count == 1)
		return (0);
	else
	{
		while (i < count)
		{
			split_arg = ft_split(values[i], ' ');
			while (*split_arg)
			{
				if (!is_valid_number(*split_arg))
						return (0); 
				split_arg++;
			}
			i++;
		}
	}
	return (1);
}

void	load_values(int argc, char **argv, t_list *list)
{
		int i;
		char **split_arg;
		
		i = 1;
		if (!is_valid_input(argc, argv))
			write(1, "Error\n", 6);
		else
		{
			while (i < argc)
			{
				split_arg = ft_split(argv[i], ' ');
				while (*split_arg)
				{
					write(1, "a\n", 2);
					ft_lstadd_front(&list, ft_lstnew(ft_atoi(*split_arg)));
					split_arg++;
				}
				i++;
			}
		}	
}