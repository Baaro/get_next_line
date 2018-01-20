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
    t_list      *head;

    head = ft_lstnew(*line, BUFF_SIZE);
    while ()
}

int     main(int argc, char **argv)
{
    int     fd;
    char    *str;
    int     i;

    i = 0;
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("Cannot open file.\n");
        exit(1);
    }
    while (str[i])
    {
        read(fd, str, BUFF_SIZE);
        printf("%s", str);
        get_next_line(fd, str);
        i++;
    }
    return (0);
}