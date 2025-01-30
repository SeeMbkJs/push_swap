/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 17:26:32 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 11:33:54 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				node_pos;
	int				cost_a;
	int				cost_b;
	int				trgt_pos;
	struct s_stack	*next;
}				t_list;

long	ft_atoi(const char	*str);
char	**ft_split(char *str, char charset);
//functions
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int value);
//int
int		get_max(t_list	*head);
int		ft_strlen(char *str);
int		is_valid_arg(char *str);
int		null_check(char *str);
int		is_dup(t_list *stack_a, int data);
int		ft_lstsize(t_list *lst);
int		ft_abs(int nb);
int		is_sorted(t_list *stack_a);
int		small_pos(t_list *stack_a);
int		high_index(t_list *stack);

void	stack_pos(t_list *stack);
void	push(t_list **src, t_list **dst);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	shift_list(t_list **stack_a);
void	stack_index(t_list *stack);
void	shift(t_list **stack);
void	rev_shift(t_list **stack);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	free_memmory(char	**str);
void	print_error_and_free(t_list **stack_a, char **str);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rr_loop(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rrr_loop(t_list **stack_a, t_list **stack_b, int *cost_a, int *cost_b);
void	target_pos(t_list *stack_a, t_list *stack_b);
void	a_cost(t_list **stack_a, int *cost_a);
void	b_cost(t_list **stack_b, int *cost_b);
void	push_all(t_list **stack_a, t_list **stack_b);
void	cont_operation(t_list *stack_a, t_list *stack_b);
void	do_moves(t_list **stack_a, t_list **stack_b);
void	sort_three_elem(t_list **stack);
void	sort(t_list **stack_a, t_list **stack_b);
void	sort_args(t_list **stack_a, t_list **stack_b);
void	ft_lstclear(t_list **lst);
void	ft_putstr(char *s);
#endif
