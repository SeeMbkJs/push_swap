/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:26:35 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 11:00:53 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	shift(stack_a);
	shift(stack_b);
}

void	rra(t_list **stack_a)
{
	rev_shift(stack_a);
}

void	rrb(t_list **stack_b)
{
	rev_shift(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b)
	{
		rev_shift(stack_a);
		rev_shift(stack_b);
	}
}
