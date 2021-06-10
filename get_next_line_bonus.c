/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:57:50 by smagdela          #+#    #+#             */
/*   Updated: 2021/06/10 19:03:35 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Je dedie cette fonction a Anna, 
sans qui elle n'aurait jamais pu voir le jour, 
et ainsi faire de moi un homme heureux <3 */

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

static int	ft_output(char **line, char *buffer, int read_buffer)
{	
	int	i;

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
		ft_strlcpy_gnl(buffer, buffer + i + 1, read_buffer - i);
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

int	get_next_line(int fd, char **line)
{
	static char		buffer[1024][BUFFER_SIZE + 1];
	int				read_buffer;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	*line = (char *)malloc(1);
	if (*line == NULL)
		return (-1);
	**line = '\0';
	if (ft_strlen(buffer[fd]) <= BUFFER_SIZE && ft_strlen(buffer[fd]) != 0)
		read_buffer = BUFFER_SIZE;
	else
		read_buffer = read(fd, buffer[fd], BUFFER_SIZE);
	while (read_buffer == BUFFER_SIZE && !ft_endofline(read_buffer, buffer[fd]))
	{
		if (ft_append(line, buffer[fd]) == -1)
			return (-1);
		read_buffer = read(fd, buffer[fd], BUFFER_SIZE);
	}
	return (ft_output(line, buffer[fd], read_buffer));
}
