/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 20:21:51 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 10:05:46 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write (1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	shift(stack_b);
	write(1, "rb\n", 3);
}

void	rrr_loop(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	rr_loop(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}
