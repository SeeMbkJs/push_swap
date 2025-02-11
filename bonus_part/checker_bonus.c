/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:26:05 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 11:03:37 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	the_last_thing(t_list **stack_a, t_list **stack_b, int size, int ac)
{
	(void)(ac);
	if (is_sorted(*stack_a) && size == ft_lstsize(*stack_a) && *stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}

void	read_input(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else
		ft_putstr_fd("Error\n", stack_a, line, stack_b);
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
		args = NULL;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	check_input(av, &stack_a);
	size = ft_lstsize(stack_a);
	line = get_next_line(0);
	while (line)
	{
		read_input(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	the_last_thing(&stack_a, &stack_b, size, ac);
	return (0);
}
