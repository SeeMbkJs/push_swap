/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-m-b <elel-m-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 09:25:46 by elel-m-b          #+#    #+#             */
/*   Updated: 2025/01/27 10:56:55 by elel-m-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strlen(char	*s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	find_line(char *buf, char c)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *buf, char *reminder)
{
	char		*tmp;
	int			read_byte;

	read_byte = 1;
	while (read_byte)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
		else if (read_byte == -1)
			return (0);
		buf[read_byte] = '\0';
		if (!reminder)
			reminder = ft_strdup("");
		tmp = reminder;
		reminder = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (find_line(buf, '\n'))
			break ;
	}
	return (reminder);
}

char	*remove_line(char	*line)
{
	char	*reminder;
	int		count;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (0);
	reminder = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*reminder == '\0')
	{
		free(reminder);
		reminder = NULL;
	}
	line[count + 1] = '\0';
	return (reminder);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * ((size_t)(BUFFER_SIZE) + 1));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, reminder);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	reminder = remove_line(line);
	return (line);
}
