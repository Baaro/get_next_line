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

static char *ft_cut(char **str, char **line)
{
    char    *pos;
    char    *del;

    pos = NULL;
    del = NULL;
    if (pos = ft_strchr((*str), '\n'))
    {
        *line = ft_strsub(str, 0, pos - str);
        *str = ft_strdup(pos + 1);
    }
    else
    {
        *line = ft_strsub(str, 0, pos - str);
        del = *str;
        *str += i;
        ft_strdel(del);
    }
    return (*line);
}

int         get_next_line(const int fd, char **line)
{
    static char     *str;
    char            *tmp;
    char            *concat;
    int             ret;
    int             i;

    i = 0;
    ret = 0;
    tmp = ft_strnew(0);
    concat = NULL;
    str = ft_strnew(BUFF_SIZE);
    while (ret = read(fd, str, BUFF_SIZE))
    {
        tmp = ft_strjoing(tmp, ft_cut(&str, line));
        ft_bzero(str, BUFF_SIZE);
        if (ft_strchr(*line), '\n')
            return (1);
    }
    ft_strdel(str);
    return (ret == -1 ? -1 : 0);
}

int         main(int argc, char **argv)
{
    int     fd;
    char    *str;
    int     ac;

    str = NULL;
    ac = argc;
    while (ac > 1)
        ac--;
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf(RED"Cannot open file.\n");
        exit(1);
    }
    get_next_line(fd, &str);
    // printf("%s\n", str);
    return (0);
}