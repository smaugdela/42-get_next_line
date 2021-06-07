/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:03:52 by smagdela          #+#    #+#             */
/*   Updated: 2021/06/07 17:42:11 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_endofline(int read_buffer, char *buffer)
{
	size_t	i;

	i = 0;
	while (i < read_buffer)
	{
		if (buffer[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

size_t	ft_strlen (const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		++i;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*big_s;
	unsigned int	i;
	unsigned int	j;

	if ((s1 == NULL || s2 == NULL))
		return (NULL);
	big_s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!big_s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		big_s[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j])
	{
		big_s[i + j] = s2[j];
		++j;
	}
	big_s[i + j] = '\0';
	return (big_s);
}
