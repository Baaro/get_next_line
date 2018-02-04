/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:28:03 by vsokolog          #+#    #+#             */
/*   Updated: 2018/02/04 13:28:04 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_cut(char **buff, int *flag)
{
	char	*pos;
	char	*tmp;
	char	*del;

	tmp = NULL;
	pos = NULL;
	del = *buff;
	if ((pos = ft_strchr((*buff), '\n')))
	{
		*flag = 1;
		tmp = ft_strsub((*buff), 0, pos - (*buff));
		*buff = ft_strdup(pos + 1);
		ft_strdel(&del);
		return (tmp);
	}
	tmp = ft_strsub((*buff), 0, ft_strlen(*buff));
	*buff = ft_strdup((*buff) + ft_strlen(*buff)); 
	ft_strdel(&del);
	return (tmp);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buff;
	char		*save;
	int			ret;
	int			flag;

	flag = 0;
	ret = 0;
	save = ft_strnew(BUFF_SIZE);
	buff = ft_strnew(0);
	while ((ret = read(fd, save, BUFF_SIZE)))
	{
		buff = ft_strjoin(buff, ft_cut(&save, &flag));
		if (flag == 1)
		{
			*line = ft_strdup(buff);
			buff = ft_strdup(save);
			ft_strdel(&save);
			return (1);
		}
		buff = ft_strdup(save);
		ft_bzero(save, BUFF_SIZE);
	}
	ft_strdel(&buff);
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
    while ((get_next_line(fd, &str)))
   		printf("%s\n", str);
    return (0);
}