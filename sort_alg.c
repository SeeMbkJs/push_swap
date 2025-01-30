/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 20:21:26 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/29 14:36:31 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_target(t_list *stack_a, int stack_b_index,
		int min_index, int trgt_pos)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index > stack_b_index && min_index > tmp->index)
		{
			trgt_pos = tmp->node_pos;
			min_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (min_index != INT_MAX)
		return (trgt_pos);
	tmp = stack_a;
	while (tmp)
	{
		if (min_index > tmp->index)
		{
			min_index = tmp->index;
			trgt_pos = tmp->node_pos;
		}
		tmp = tmp->next;
	}
	return (trgt_pos);
}

void	target_pos(t_list *stack_a, t_list *stack_b)
{
	int	trgt_pos;

	trgt_pos = 0;
	stack_pos(stack_a);
	stack_pos(stack_b);
	while (stack_b)
	{
		trgt_pos = get_target(stack_a, stack_b->index, INT_MAX, 0);
		stack_b->trgt_pos = trgt_pos;
		stack_b = stack_b->next;
	}
}

void	cont_operation(t_list *stack_a, t_list *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		if (stack_b->node_pos <= size_b / 2)
			stack_b->cost_b = stack_b->node_pos;
		else
			stack_b->cost_b = -(size_b - stack_b->node_pos);
		if (size_a / 2 >= stack_b->trgt_pos)
			stack_b->cost_a = stack_b->trgt_pos;
		else
			stack_b->cost_a = -(size_a - stack_b->trgt_pos);
		stack_b = stack_b->next;
	}
}

void	do_moves(t_list **stack_a, t_list **stack_b)
{
	int		cheap_cost;
	int		cost_a;
	int		cost_b;
	t_list	*tmp;

	cheap_cost = INT_MAX;
	tmp = (*stack_b);
	while (tmp)
	{
		if (cheap_cost > ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b))
		{
			cheap_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	if (cost_a < 0 && cost_b < 0)
		rrr_loop(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rr_loop(stack_a, stack_b, &cost_a, &cost_b);
	a_cost(stack_a, &cost_a);
	b_cost(stack_b, &cost_b);
	pa(stack_b, stack_a);
}

void	sort_three_elem(t_list **stack)
{
	int		index;

	index = high_index(*stack);
	if ((*stack)->index == index)
		ra(stack);
	else if ((*stack)->next->index == index)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}
