/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 20:21:57 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 10:05:00 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = *src;
		(*src) = (*src)->next;
		ft_lstadd_front(dst, tmp);
	}
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	if (*stack_b)
	{
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
	{
		push(stack_a, stack_b);
		write (1, "pb\n", 3);
	}
}
