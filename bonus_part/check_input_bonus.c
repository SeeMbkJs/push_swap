/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:25:56 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 10:54:18 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	size)
{
	size_t		i;
	size_t		src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	if (dst)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy (str, s1, len1 + 1);
	ft_strlcpy (str + len1, s2, len2 + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t	len)
{
	char	*new_str;
	size_t	legnth_s;
	size_t	li_bghina_yb9aw;

	legnth_s = 0;
	if (!s)
		return (NULL);
	while (s[legnth_s])
		legnth_s++;
	li_bghina_yb9aw = 0;
	if (legnth_s > start)
		li_bghina_yb9aw = legnth_s - start;
	if (li_bghina_yb9aw > len)
		li_bghina_yb9aw = len;
	new_str = (char *)malloc(sizeof(char) * (li_bghina_yb9aw + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s + start, li_bghina_yb9aw + 1);
	return (new_str);
}
