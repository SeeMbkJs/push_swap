/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 17:27:51 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/26 18:49:43 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	null_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(t_list *stack_a, int data)
{
	while (stack_a)
	{
		if (stack_a->value == data)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_memmory(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_error_and_free(t_list **stack_a, char **str)
{
	int	i;

	i = 0;
	ft_lstclear(stack_a);
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	write (2, "Error\n", 6);
	exit(1);
}
