/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 21:16:26 by vsokolog          #+#    #+#             */
/*   Updated: 2018/01/19 21:16:27 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     get_next_line(const int fd, char **line)
{

}

int     main(int argc, char **argv)
{
    int fd;
    char    *str;

    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("Cannot open file.\n");
        exit(1);
    }
    read(fd, str, 1);
    printf("%c", str);
    get_next_line(fd, str);
    return (0);
}