/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:26:49 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/29 16:56:45 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	else
		return ;
}

void	sa(t_list **stack_a)
{
	if (*stack_a && (*stack_a)->next)
	{
		swap(stack_a);
	}
}

void	sb(t_list **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		swap(stack_b);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sa(stack_b);
}
