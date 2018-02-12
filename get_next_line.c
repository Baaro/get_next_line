/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:49:39 by vsokolog          #+#    #+#             */
/*   Updated: 2018/02/09 00:26:54 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check(char **str, char *bf, char **line, int ret)
{
	char	*del;
	char	*pos;

	pos = NULL;
	del = *str;
	(*str = ft_strjoin(*str, bf)) ? ft_strdel(&del) : 0;
	ft_strclr(bf);
	if ((pos = ft_strchr(*str, '\n')))
	{
		(*line = ft_strsub(*str, 0, pos - (*str)));
		del = *str;
		(*str = ft_strdup(pos + 1)) ? ft_strdel(&del) : 0;
		return (1);
	}
	if (ret == 0 && ft_strlen(*str))
	{
		(*line = ft_strdup(*str)) ? ft_strdel(str) : 0;
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*str;
	char			bf[BUFF_SIZE + 1];
	int				ret;

	!str ? str = ft_strnew(BUFF_SIZE) : 0;
	if (fd < 0 || !line || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	while (!ft_strchr(str,'\n') && ((ret = read(fd, bf, BUFF_SIZE))))
	{
		bf[ret] = '\0';
		if (ft_check(&str, bf, line, ret))
			return (1);
	}
	if (ret == -1)
		return (-1);
	return (ft_check(&str, bf, line, ret));
}
