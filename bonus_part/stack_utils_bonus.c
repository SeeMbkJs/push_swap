/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:26:42 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 11:02:23 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

static	int	is_sep(char c, char charset)
{
	return (c == charset);
}

static	char	*ft_strcat(char *src, int start, int end)
{
	char		*res;
	int			i;

	res = malloc(sizeof(char) * (end - start + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		res[i] = src[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char charset)
{
	char	**res;
	int		start;
	int		i;
	int		k;

	i = 0;
	start = 0;
	k = 0;
	res = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		start = i;
		while (str[i] && !is_sep(str[i], charset))
			i++;
		if (start < i)
			res[k++] = ft_strcat(str, start, i);
	}
	res[k] = NULL;
	return (res);
}
