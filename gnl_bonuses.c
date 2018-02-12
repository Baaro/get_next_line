/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonuses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 20:30:32 by vsokolog          #+#    #+#             */
/*   Updated: 2018/02/11 20:30:39 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lst *ft_lst_create(const int fd)
{
	t_lst	*lst;

	if (!(lst = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	if (lst->str == NULL)
		lst->str = malloc(BUFF_SIZE);
	lst->fd = fd;
	lst->next = NULL;
	return (lst);
}

static int	ft_check(t_lst **lst, char **bf, char **line, int ret)
{
	char	*del;
	char	*pos;

	pos = NULL;
	del = lst->str;
	lst->str = ft_strjoin(lst->str, *bf) ? ft_strdel(&del) : 0;
	ft_strclr(*bf);
	if ((pos = ft_strchr(lst->str, '\n')))
	{
		(*line = ft_strsub(lst->str, 0, pos - (lst->str)));
		(del = lst->str) ? ft_strdel(bf) : 0;
		(lst->str = ft_strdup(pos + 1)) ? ft_strdel(&del) : 0;
		return (1);
	}
	if (ret == 0 && !ft_strchr(lst->str, '\n'))
	{
		(*line = ft_strdup(lst->str)) ? ft_strdel(lst->str) : 0;
		ft_strdel(bf);
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static t_lst	*lst;
	char			*bf;
	int				ret;

	ret = 0;
	bf = ft_strnew(BUFF_SIZE);
	!lst ? (lst = ft_lst_create(fd)) : 0;
	ft_iffd(lst, fd) ? :;
	if ((fd < 0 || !line || read(fd, bf, 0) < 0))
		return (-1);
	while (ret = read(fd, bf, BUFF_SIZE))
	{
		bf[ret + 1] = '\0';
		if ((ft_check(&lst, &bf, line, ret)))
			return (1);
	}
	if (ret == 0 && ft_strlen(str))
	{
		if (ft_check(&str, &bf, line, ret))
			return (1);
	}
	ft_strdel(&bf);
	ft_strdel(lst);
	return (ret == -1 ? -1 : 0);
}
