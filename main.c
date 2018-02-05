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

int main(int argc, char **argv)
{
    char    *str;
    int   fd;

    str = NULL;
    fd = 0;
    while (argc > 1)
        argc--;
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf(RED"Cannot open file.\n");
        exit(0);
    }
    while (get_next_line(fd, &str))
        printf("%s\n", str);
    return (0);
}