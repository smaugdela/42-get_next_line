/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:35:08 by smagdela          #+#    #+#             */
/*   Updated: 2021/06/08 18:51:49 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	i = 1;

	while (get_next_line(fd, &line) > 0)
	{
		printf("Ligne %d : |%s|\n", i, line);
		++i;
	}
	printf("Ligne %d : |%s|\n", i, line);
	close(fd);
	return (0);
}
