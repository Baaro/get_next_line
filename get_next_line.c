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
static int ft_to_return(char **line, char *str, char *save, int flag)
{
	if (flag == 1)
	{
		*line = ft_strdup(str);
		free(str);
		str = ft_strdup(save);
		ft_strdel(&save);
		return (1);
	}
	return (0);
}
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
	static char	*str;
	char		*save;
	char		*tmp;
	int			ret;
	int			flag;

	flag = 0;
	ret = 0;
	tmp = NULL;
	save = ft_strnew(BUFF_SIZE); 
	if (str == NULL)
		str = ft_strnew(0);
	while ((ret = read(fd, save, BUFF_SIZE)))
	{
		str = ft_strjoin(str, tmp = ft_cut(&save, &flag));
		ft_strdel(&tmp);
		if (ft_to_return(line, str, save, flag))
			return (1);
		*line = ft_strdup(str);
		ft_bzero(save, BUFF_SIZE);
	}
	ft_strdel(&str);
	return (ret == -1 ? -1 : 0);
}
