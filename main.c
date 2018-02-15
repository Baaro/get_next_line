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
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd = open("test", O_RDONLY);
    int     fd2 = open("test2", O_RDONLY);
    int     fd3 = open("test3", O_RDONLY);
    int     ac;
    char    *av;
    char    *line;

    ac = argc;
    av = *argv;
    while (ac != 1)
        ac--;
    get_next_line(fd, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd2, &line);
    printf("%s\n", line);
    free(line);
    get_next_line(fd3, &line);
    printf("%s\n", line);
    free(line);
    return (0);
}