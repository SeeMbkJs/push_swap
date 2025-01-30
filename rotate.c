/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 20:21:19 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:45 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	shift(stack_a);
	shift(stack_b);
	ft_putstr("rr\n");
}

void	rra(t_list **stack_a)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *stack_a;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack_a;
	*stack_a = current;
	ft_putstr("rra\n");
}

void	rrb(t_list **stack_b)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *stack_b;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack_b;
	*stack_b = current;
	write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_shift(stack_a);
	rev_shift(stack_b);
	write(1, "rrr\n", 4);
}
