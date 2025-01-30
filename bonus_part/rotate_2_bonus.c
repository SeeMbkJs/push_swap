/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:47:18 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/29 14:45:56 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rev_shift(t_list **stack)
{
	t_list	*prev;
	t_list	*current;

	if (!stack || !*stack)
		return ;
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

void	shift(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = (*stack)->next;
		last = ft_lstlast(*stack);
		last->next = (*stack);
		(*stack)->next = NULL;
		(*stack) = tmp;
	}
}

void	ra(t_list **stack_a)
{
	shift(stack_a);
}

void	rb(t_list **stack_b)
{
	shift(stack_b);
}
