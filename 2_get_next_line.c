/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:08:43 by vsokolog          #+#    #+#             */
/*   Updated: 2018/02/06 17:08:45 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static  int ft_check(char **line, char **bf, int ret)
{
    static char *lft;
    char        *tmp;
    char        *del;
    char        *pos;

    pos = NULL;
    tmp = NULL;
    del = lft;
    !lft ? lft = ft_strnew(0) : 0;
    if ((pos = ft_strchr(*bf, '\n')))
    {
        (*line = ft_strjoin(lft, tmp = ft_strsub(*bf, 0, pos - (*bf))))
        ? ft_strclr(*bf) : 0;
        ft_strdel(&tmp);
        (lft = ft_strdup(pos + 1)) ? ft_strdel(&del) : 0;
        return (1);
    }
    if (ret == 0 && !ft_strchr(*bf, '\n'))
    {
        (*line = ft_strjoin(lft, tmp = ft_strsub(*bf, 0, ft_strlen(*bf)))) 
        ? ft_strdel(bf) : 0;
        ft_strdel(&lft);
        return (1);
    }
    (lft = ft_strjoin(lft, tmp = ft_strsub(*bf, 0, ft_strlen(*bf))))
    ? ft_strclr(*bf) : 0;
    ft_strdel(&tmp);
    return(0);
}
int         get_next_line(const int fd, char **line)
{
    char            *bf;    // For read from file
    char            *tmp;   // Free memory
    int             ret;    // Containing size of bf, or returned value of read

    tmp = NULL;
    bf = ft_strnew(BUFF_SIZE);
    if ((fd < 0 || !line || read(fd, bf, 0) < 0))
		return (-1);
    while ((ret = read(fd, bf, BUFF_SIZE)))
    {   
        bf[ret] = '\0';
        if (ft_check(line, &bf, ret))
            return (1);
    }
    return (0);
}