/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:03:19 by smagdela          #+#    #+#             */
/*   Updated: 2021/06/10 16:14:48 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// Je dedie cette focntion a Anna, sans qui elle n'aurait jamais pu voire le jour, et faire de moi un homme heureux.
static int	ft_append(char **line, char *buffer)
{
	char	*tmp_line;

	tmp_line = ft_strjoin_gnl(*line, buffer);
	if (tmp_line == NULL)
		return (-1);
	free(*line);
	*line = ft_strdup(tmp_line);
	free(tmp_line);
	if (line == NULL)
		return (-1);
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				read_buffer;
	int				i;

	if (BUFFER_SIZE < 1)
		return (-1);
	*line = (char *)malloc(1);
	if (*line == NULL)
		return (-1);
	**line = '\0';
	if (ft_strlen(buffer) <= BUFFER_SIZE && ft_strlen(buffer) != 0)
		read_buffer = BUFFER_SIZE;
	else
		read_buffer = read(fd, buffer, BUFFER_SIZE);
	while (read_buffer == BUFFER_SIZE && !ft_endofline(read_buffer, buffer))
	{
		if (ft_append(line, buffer) == -1)
			return (-1);
		read_buffer = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_buffer == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	else if (ft_endofline(read_buffer, buffer))
	{
		i = 0;
		while (buffer[i] != '\n')
			++i;
		if (ft_append(line, buffer) == -1)
			return (-1);
		read_buffer = read_buffer - i++;
		ft_strlcpy_gnl(buffer, buffer + i, read_buffer);
		return (1);
	}
	else
	{
		buffer[read_buffer] = '\0';
		ft_append(line, buffer);
		buffer[0] = '\0';
		return (0);
	}
}
