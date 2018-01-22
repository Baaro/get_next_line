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
    char        *str;
    int         i;
    int         j;
    int         f;

    f = 0;
    j = 0;
    i = 0;
    str = *line;
    if (!(str = ft_strnew(ft_strlen((*line)))))
    {
        free(str);
        return (-1);
    }
    if (!(f = read(fd, str, 1)))
    {
        ft_putstr("Cannot read file\n");
        return (-1);
    }
    printf("%s", str);
    // while (str[i] != '\n')
    //     printf("%c\n", str[i++]);
    // while (str[i] != '\n')
    //     i++;
    // while (j < i || str[j] == '\n')
    // {
    //     // ft_putstr(&str[j]);
    //     // ft_putstr("\n");
    //     j++;
    // }
    return (0);

}

int     main(int argc, char **argv)
{
    int     fd;
    char    *str;
    
    str = (char*)malloc(sizeof(char) * 100);
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("Cannot open file.\n");
        exit(1);
    }
    // read(fd, str, BUFF_SIZE);
    get_next_line(fd, &str);
    return (0);
}