/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:02:18 by vsokolog          #+#    #+#             */
/*   Updated: 2018/02/05 16:02:19 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
    static char *str;
    char        *tmp;
    int         ret;
    int         flag;

    ret = 0;
    tmp = NULL;
    ft_strdel(*line);
    *line = ft_strnew(0);
    while ((ret = read(fd, str, BUFF_SIZE)))
    {
        *line = ft_strjoin(*line, tmp = ft_cut(&str, &flag));
        ft_strdel(&tmp);
        if (flag == 1)
            return (1);
    }
}
