/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 17:29:06 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 11:30:58 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 100

# endif

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}				t_list;

long	ft_atoi(const char	*str);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int value);

int		is_dup(t_list *stack_a, int data);
int		is_valid_arg(char	*str);
int		null_check(char	*str);
int		ft_lstsize(t_list*lst);
int		is_sorted(t_list	*stack_a);
int		ft_strcmp(char	*s1, char	*s2);
int		ft_strlen(char	*s);

void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_memmory(char	**str);
void	print_error_and_free(t_list **stack_a, char **str);
void	push(t_list **src, t_list **dst);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	shift(t_list **stack);
void	rev_shift(t_list **stack);
void	the_last_thing(t_list **stack_a, t_list **stack_b, int size, int ac);
void	ft_lstclear(t_list **lst);
void	ft_putstr_fd(char *s, t_list **stack_a, char *line, t_list **stack_b);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t	len);
char	*ft_substr(char const *s, unsigned int start, size_t	len);
char	**ft_split(char *str, char charset);
char	*ft_strdup(const char	*src);
char	*remove_line(char	*line);
char	*get_next_line(int fd);
char	*read_line(int fd, char *buf, char *reminder);
#endif
