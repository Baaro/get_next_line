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

static int  ft_check(char **line, char **buff, char **lft, int ret)
{
    char    *del;   // Free memory
    char    *pos;   // Find '\n' in the buff
    char    *tmp;

    tmp = NULL;
    pos = NULL;
    if (*lft == NULL)
        *lft = ft_strnew(0);
    del = *lft;
    if ((pos = ft_strchr(*buff, '\n')))
    {
        *line = ft_strjoin(*lft, tmp = ft_strsub(*buff, 0, pos - (*buff)));
        ft_strdel(&tmp);
        (*lft = ft_strdup(pos + 1)) ? ft_strdel(&del) : 0;
        return (1);
    }
    *lft = ft_strjoin(*lft, tmp = ft_strsub((*buff), 0, ft_strlen(*buff)));
    ft_strdel(&tmp);
    if (ret > 0 && (ft_strlen(*buff) > 0))
    {
        *line = ft_strdup(lft);
        ft_strdel(&del);
        ft_bzero(*buff, BUFF_SIZE);
        return (1);
    }
    return (0);
}

int get_next_line(const int fd, char **line)
{
    static char     *lft;  // Save what is left after ft_check
    char            *buff;  // For read from file
    char            *tmp;   // Free memory
    int             ret;    // Containing size of buff, or returned value of read

    lft = NULL;
    tmp = NULL;
    buff = ft_strnew(BUFF_SIZE);
    while ((ret = read(fd, buff, BUFF_SIZE)))
    {
        // printf("%s\n", buff);
        if (ft_check(line, &buff, &lft, ret))
            return (1);
    }
    return (0);
}