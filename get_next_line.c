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
    else
    {
        *line = ft_strdup(tmp);
        return ();
    }
    // Add a function which must check the string if she hasn't a \n or \0 must return a str
    return (0);
}

int         get_next_line(const int fd, char **line)
{
    static char     *str;
    char            *str_cut;
    char            *tmp;
    int             ret;
    int             i;

    i = 0;
    ret = 0;
    str = NULL;
    str_cut = NULL;
    tmp = ft_strnew(BUFF_SIZE);
    while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
    {
        tmp = ft_strnew(BUFF_SIZE);
        str_cut = ft_check(&tmp, &i);
        if (ft_cut(tmp, &(*line), i) == 1)
        {
           free(tmp);
           // str += (++i);
           return (1);
        }
        free(str);
    }
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
    // str = (char*)malloc(sizeof(char) * 100);
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf(RED"Cannot open file.\n");
        exit(1);
    }
    get_next_line(fd, &str);
    // printf("%s\n", str);
    return (0);
}