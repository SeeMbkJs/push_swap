/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:26:22 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/29 17:04:52 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_putstr_fd(char *s, t_list **stack_a, char *line, t_list **stack_b)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	free(line);
	while (s[i] != '\0')
	{
		write (2, &s[i], 1);
		i++;
	}
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

long	ft_atoi(const char	*str)
{
	int		i;
	int		signe;
	long	res;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((long)(res * signe));
}
