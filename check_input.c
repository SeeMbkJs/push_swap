/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:20:44 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/26 18:49:06 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	is_sep(char c, char charset)
{
	return (c == charset);
}

static	char	*ft_strcat(char *src, int start, int end)
{
	char	*res;
	int		i;

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
