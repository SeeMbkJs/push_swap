/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 20:21:31 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/29 14:35:50 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	high_index(t_list *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	shift_list(t_list **stack_a)
{
	int	pos;

	stack_pos(*stack_a);
	pos = small_pos(*stack_a);
	if (pos > (ft_lstsize(*stack_a) / 2))
	{
		while (!is_sorted(*stack_a))
			rra(stack_a);
	}
	else
		while (!is_sorted(*stack_a))
			ra(stack_a);
}

int	small_pos(t_list *stack_a)
{
	int		index;
	int		pos;

	index = INT_MAX;
	pos = 0;
	while (stack_a)
	{
		if (stack_a->index < index)
		{
			index = stack_a->index;
			pos = stack_a->node_pos;
		}
		stack_a = stack_a->next;
	}
	return (pos);
}

void	rev_shift(t_list **stack)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	stack_pos(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->node_pos = i;
		stack = stack->next;
		i++;
	}
}
