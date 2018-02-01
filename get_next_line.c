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

static char *ft_check(char **str, int *i)
{
    char    *tmp;

    tmp = NULL;
    while ((*str)[*i] != '\0')
    {
        if ((*str)[(*i) + 1] == '\n' || (*str)[(*i) + 1] == '\0')
            break ;
        (*i)++;
    }
    if (!(tmp = ft_strsub((const char*)(*str), (unsigned int)(**str), *i)))
    {
        free(tmp);
        return (0);
    }
    return (tmp);
}

static int ft_cut(char *tmp, char **line, int i)
{
    if (tmp[i + 1] == '\n')
    {   
        *line = ft_strdup(tmp);
        free(tmp);
        return (1);
    }
    if (tmp[i + 1] == '\0')
    {
        *line = ft_strdup(tmp);
        free(tmp);
    }
    return (0);
}

int         get_next_line(const int fd, char **line)
{
    static char     *str;
    char            *tmp;
    int             ret;
    int             i;

    ret = 0;
    i = 0;
    str = NULL;
    tmp = NULL;
    if (!(str = ft_strnew(BUFF_SIZE)))
    {
        free(str);
        return (-1);
    }
    while ((ret = read(fd, str, BUFF_SIZE)) > 0)
    {
        if (!(str = ft_strnew(BUFF_SIZE)))
        {
            free(str);
            return (-1);
        }
    }
    tmp = ft_check(&str, &i);
    if (ft_cut(tmp, &(*line), i) == 1)
    {
        free(tmp);
        str += (++i);
        return (1);
    }
    free(str);
    return (ret == -1 ? -1 : 0);
}

int         main(int argc, char **argv)
{
    int     fd;
    char    *str;
    int     ac;

    ac = argc;
    while (ac > 1)
        ac--;
    str = (char*)malloc(sizeof(char) * 100);
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("Cannot open file.\n");
        exit(1);
    }
    read(fd, str, 50);
    get_next_line(fd, &str);
    // printf("%s", str);
    return (0);
}