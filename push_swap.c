/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 17:26:17 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/29 14:31:35 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	push_all(stack_a, stack_b);
	sort_three_elem(stack_a);
	while (*stack_b)
	{
		target_pos(*stack_a, *stack_b);
		cont_operation(*stack_a, *stack_b);
		do_moves(stack_a, stack_b);
	}
	while (!is_sorted(*stack_a))
		shift_list(stack_a);
}

void	sort_args(t_list **stack_a, t_list **stack_b)
{
	stack_index(*stack_a);
	if (ft_lstsize(*stack_a) == 2)
	{
		if (!is_sorted(*stack_a))
			ra(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		sort_three_elem(stack_a);
	else
		sort(stack_a, stack_b);
}

static	int	process_args(char **args, t_list **stack_a)
{
	int			j;
	long		data;

	j = 0;
	while (args[j])
	{
		if (!is_valid_arg(args[j]))
			return (0);
		data = ft_atoi(args[j]);
		if (data > INT_MAX || data < INT_MIN)
			return (0);
		if (is_dup(*stack_a, data))
			return (0);
		ft_lstadd_back(stack_a, ft_lstnew(data));
		j++;
	}
	return (1);
}

static	void	check_input(char **av, t_list **stack_a)
{
	int		i;
	char	**args;

	i = 1;
	while (av[i])
	{
		if (!av[i] || av[i][0] == '\0' || null_check(av[i]))
			print_error_and_free(stack_a, NULL);
		args = ft_split(av[i], ' ');
		if (!args)
			print_error_and_free(stack_a, NULL);
		if (!process_args(args, stack_a))
			print_error_and_free(stack_a, args);
		free_memmory(args);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
		check_input(av, &stack_a);
	if (stack_a && !is_sorted(stack_a))
		sort_args(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
}
