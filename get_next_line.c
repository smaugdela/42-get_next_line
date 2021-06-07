/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:03:19 by smagdela          #+#    #+#             */
/*   Updated: 2021/06/07 19:26:02 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static size_t	overflow = 0;
	char			*buffer;
	int				read_buffer;
	char 			*tmp_line;
	int				i;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (-1);
	read_buffer = read(fd, buffer, BUFFER_SIZE);
	if (overflow) // si il y a eu du debordement a la lecture de la precedente ligne, on ecrit le debut de la nouvelle ligne avant de read a nouveau.
	{
		*(buffer + BUFFER_SIZE) = '\0';
		buffer = buffer + overflow;
		i = 0;
		while (buffer[i] != '\n')
			++i;
		buffer[i] = '\0';
		tmp_line = ft_strjoin(*line, buffer);
		line = &tmp_line;
		overflow = overflow - i;
	}
	while (read_buffer == BUFFER_SIZE && !ft_endofline(read_buffer, buffer)) // on ecrit tant qu'on ne rencontre pas de '\n' ou d'EOF.
	{
		buffer[read_buffer] = '\0';
		tmp_line = ft_strjoin(*line, buffer);
		line = &tmp_line;
		read_buffer = read(fd, buffer, BUFFER_SIZE);
	}
	if (read_buffer == -1) // si une erreur survient, on free.
	{
		overflow = 0;
		free(buffer);
		return (-1);
	}
	else if (ft_endofline(read_buffer, buffer)) // si l'on rencontre un '\n', on copie la premiere portion, et on stocke le debordement dans overflow.
	{
		i = 0;
		while (buffer[i] != '\n')
			++i;
		buffer[i] = '\0';
		tmp_line = ft_strjoin(*line, buffer);
		line = &tmp_line;
		overflow = BUFFER_SIZE - i;
		return (1);
	}
	else // si l'on rencontre un EOF sans '\n' prealable, on copie la fin, et on stoppe le programme (overflow = 0, return (0) ).
	{
		buffer[read_buffer] = '\0';
		tmp_line = ft_strjoin(*line, buffer);
		line = &tmp_line;
		overflow = 0;
		free(buffer);
		return (0);
	}
}
