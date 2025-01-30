/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 17:27:37 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/29 16:52:04 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return ((res * signe));
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char	*src)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_max(t_list *head)
{
	int		max_value;
	t_list	*ptr;

	max_value = INT_MIN;
	ptr = head;
	while (ptr)
	{
		if (ptr->index == 0 && ptr->value >= max_value)
			max_value = ptr->value;
		ptr = ptr->next;
	}
	return (max_value);
}
