/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:49:39 by vsokolog          #+#    #+#             */
/*   Updated: 2018/02/07 20:49:41 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_check(char **str, char **bf, char **line)
{
    char    *del;
    char    *pos;

    pos = NULL;
    del = *str;
    (*str = ft_strjoin(*str, *bf)) ? ft_strdel(&del) : 0;
    if ((pos = ft_strchr(*str, '\n')))
    {
        (*line = ft_strsub(*str, 0, pos - (*str)));
        del = *str;
        (*str = ft_strdup(pos + 1)) ? ft_strdel(&del) : 0;
        ft_strclr(*bf);
        return (1);
    }
    ft_strclr(*bf);
    return (0);
}
int         get_next_line(const int fd, char **line)
{
    static char *str;
    char        *bf;
    int         ret;

    bf = NULL;
    bf = ft_strnew(BUFF_SIZE);
    !str ? str = ft_strnew(BUFF_SIZE) : 0;
    if ((fd < 0 || !line || read(fd, bf, 0) < 0))
		return (-1);
    while ((ret = read(fd, bf, BUFF_SIZE)))
    {
        bf[ret + 1] = '\0'; 
        if (ft_check(&str, &bf, line))
            return (1);
    }
    if (ret == 0 && ft_strlen(str))
    {
        (*line = ft_strdup(str)) ? ft_strdel(&str) : 0;
        return (1);
    }
    ft_strdel(&str);
    return (0);
}