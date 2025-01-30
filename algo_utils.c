/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 20:22:18 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 10:09:30 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all(t_list **stack_a, t_list **stack_b)
{
	int		pushed;
	int		i;
	int		size;

	pushed = 0;
	i = 0;
	size = ft_lstsize(*stack_a);
	while ((size - pushed) > 3 && i < size && size > 5)
	{
		if ((ft_lstsize(*stack_a) / 2 >= (*stack_a)->index))
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while ((size - pushed) > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	stack_index(t_list *head)
{
	t_list	*ptr;
	int		size;
	int		max_value;

	size = ft_lstsize(head);
	while (size)
	{
		ptr = head;
		max_value = get_max(head);
		ptr = head;
		while (ptr)
		{
			if (ptr->index == 0 && ptr->value == max_value)
			{
				ptr->index = size;
				break ;
			}
			ptr = ptr->next;
		}
		size--;
	}
}

void	a_cost(t_list **stack_a, int *cost_a)
{
	while (*cost_a < 0)
	{
		rra(stack_a);
		(*cost_a)++;
	}
	while (*cost_a > 0)
	{
		ra(stack_a);
		(*cost_a)--;
	}
}

void	b_cost(t_list **stack_b, int *cost_b)
{
	while (*cost_b < 0)
	{
		rrb(stack_b);
		(*cost_b)++;
	}
	while (*cost_b > 0)
	{
		rb(stack_b);
		(*cost_b)--;
	}
}
