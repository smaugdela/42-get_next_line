/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:03:32 by smagdela          #+#    #+#             */
/*   Updated: 2021/06/07 19:25:54 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

// # define BUFFER_SIZE 4096

int 	get_next_line(int fd, char **line);
int		ft_endofline(int read_buffer, char *buffer);
size_t	ft_strlen (const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
