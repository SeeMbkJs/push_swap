/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:26:28 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/29 16:56:05 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (!src)
		return ;
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
		push(stack_b, stack_a);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b)
		push(stack_a, stack_b);
}
