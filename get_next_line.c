/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:03:19 by smagdela          #+#    #+#             */
/*   Updated: 2021/06/09 18:21:33 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				read_buffer;
	char 			*tmp_line;
	int				i;

	*line = (char *)malloc(1);
	if (*line == NULL)
		return (-1);
	**line = '\0';
	tmp_line = (char *)malloc(1);
	if (tmp_line == NULL)
		return (-1);
	*tmp_line = '\0';
	if (ft_strlen(buffer) <= BUFFER_SIZE && ft_strlen(buffer) != 0) // si il y a eu du debordement a la lecture de la precedente ligne.
		read_buffer = BUFFER_SIZE;
	else // seulement si il n'y a pas de debordement, on lit le fichier.
		read_buffer = read(fd, buffer, BUFFER_SIZE);
	while (read_buffer == BUFFER_SIZE && !ft_endofline(read_buffer, buffer)) // on ecrit tant qu'on ne rencontre pas de '\n' ou d'EOF.
	{
		free(tmp_line);
		tmp_line = ft_strjoin_gnl(*line, buffer);
		if (tmp_line == NULL)
			return (-1);
		free(*line);
		*line = ft_strdup(tmp_line);
		if (line == NULL)
			return (-1);
		read_buffer = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_buffer == -1) // si une erreur survient, on free.
	{
		free(*line);
		*line = NULL;
		free(tmp_line);
		return (-1);
	}
	else if (ft_endofline(read_buffer, buffer)) // si l'on rencontre un '\n', on copie la premiere portion, et on actualise le buffer.
	{
		i = 0;
		while (buffer[i] != '\n')
			++i;
		free(tmp_line);
		tmp_line = ft_strjoin_gnl(*line, buffer);
		if (tmp_line == NULL)
			return (-1);
		free(*line);
		*line = ft_strdup(tmp_line);
		if (line == NULL)
			return (-1);
		free(tmp_line);
		read_buffer = read_buffer - i++;
		ft_strlcpy_gnl(buffer, buffer + i, read_buffer);
		return (1);
	}
	else // si l'on rencontre un EOF sans '\n' prealable, on copie la fin, et on stoppe le programme (return (0) ).
	{
		buffer[read_buffer] = '\0';
		free(tmp_line);
		tmp_line = ft_strjoin_gnl(*line, buffer);
		if (tmp_line == NULL)
			return (-1);
		free(*line);
		*line = ft_strdup(tmp_line);
		if (line == NULL)
			return (-1);
		free(tmp_line);
		return (0);
	}
}
