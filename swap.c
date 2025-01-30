/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 20:21:38 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 10:10:48 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list		*tmp;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
}

void	sa(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		swap(stack_a);
		write (1, "sa\n", 3);
	}
}

void	sb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		swap(stack_b);
		write (1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sa(stack_b);
	write (1, "sa\n", 3);
}
