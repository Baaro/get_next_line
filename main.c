/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:26:37 by vsokolog          #+#    #+#             */
/*   Updated: 2018/02/05 16:26:38 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc == 1)
		fd = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Cannot open file.\n");
		exit(0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
