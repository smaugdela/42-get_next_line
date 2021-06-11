/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:35:08 by smagdela          #+#    #+#             */
/*   Updated: 2021/06/10 18:48:58 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	i = 1;

	while (get_next_line(0, &line) > 0)
	{
		printf("Ligne %d : |%s|\n", i, line);
		free(line);
		++i;
	}
	printf("Ligne %d : |%s|\n", i, line);
	close(fd);
	return (0);
}
