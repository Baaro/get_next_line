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

static t_lst	*ft_lst_create(const int fd)
{
	t_lst	*head;

	head = (t_lst*)malloc(sizeof(t_lst));
	head->fd = fd;
	!head->str ? head->str = ft_strnew(0) : 0;
	head->next = NULL;
	return (head);
}

static void		ft_find_fd(t_lst **head, t_lst *new, const int fd)
{
	t_lst	*tmp;

	if ((*head) == NULL)
		*head = ft_lst_create(fd);
	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->fd == new->fd)
			break ;
		tmp = tmp->next;
	}
	if (tmp->fd == new->fd)
	{
		new->next = tmp->next;
		tmp->next = new;
		tmp->str = new->str;
	}
	else
	{
		tmp->next = new;
		new->str = tmp->str;
		new->next = NULL;
	}
}

static int		ft_check(char **str, char *bf, char **line, int ret)
{
	char	*del;
	char	*pos;

	if (*str == NULL)
		return (0);
	pos = NULL;
	del = *str;
	(*str = ft_strjoin(*str, bf)) ? ft_strdel(&del) : 0;
	ft_strclr(bf);
	if ((pos = ft_strchr(*str, '\n')))
	{
		(*line = ft_strsub(*str, 0, pos - (*str))) ? del = *str : 0;
		(*str = ft_strdup(pos + 1)) ? ft_strdel(&del) : 0;
		ft_strdel(&bf);
		return (1);
	}
	if (ret == 0 && (*str[0] != '\0'))
	{
		(*line = ft_strdup(*str)) ? ft_strdel(&bf) : 0;
		 ft_strdel(str);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_lst	*head;
	t_lst			*new;
	char			*bf;
	int				ret;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	ft_find_fd(&head, new = ft_lst_create(fd), fd);
	bf = ft_strnew(BUFF_SIZE);
	while (1)
	{
		if (new->str && !ft_strchr(new->str, '\n'))
		{
			ret = read(fd, bf, BUFF_SIZE);
			bf[ret] = '\0';
		}
		if (ret == -1)
			return (-1);
		if (ft_check(&(new->str), bf, line, ret))
			return (1);
		if (ret == 0 && new->str[0] == '\0')
			break ;
	}
	return (0);
}
