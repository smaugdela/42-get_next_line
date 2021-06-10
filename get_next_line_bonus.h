/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:53:44 by smagdela          #+#    #+#             */
/*   Updated: 2021/06/10 18:54:05 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int		get_next_line(int fd, char **line);
int		ft_endofline(int read_buffer, char *buffer);
size_t	ft_strlen (const char *str);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *str);

#endif
