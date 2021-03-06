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
	head->str = ft_strnew(0);
	head->next = NULL;
	return (head);
}

static t_lst	*ft_find_fd(t_lst **head, const int fd)
{
	t_lst	*tmp;

	if ((*head) == NULL)
		*head = ft_lst_create(fd);
	tmp = *head;
	while (tmp->next != NULL)
	{
		if (tmp->fd == fd)
			break ;
		tmp = tmp->next;
	}
	return (tmp->fd == fd ? tmp : (tmp->next = ft_lst_create(fd)));
}

static int		ft_check(t_lst *lst, char *bf, char **line, int ret)
{
	char	*del;
	char	*pos;

	if (lst->str == NULL)
		return (0);
	pos = NULL;
	del = lst->str;
	(lst->str = ft_strjoin(lst->str, bf)) ? ft_strdel(&del) : 0;
	ft_strclr(bf);
	if ((pos = ft_strchr(lst->str, '\n')))
	{
		*line = ft_strsub(lst->str, 0, pos - (lst->str));
		del = lst->str;
		(lst->str = ft_strdup(pos + 1)) ? ft_strdel(&del) : 0;
		ft_strdel(&bf);
		return (1);
	}
	if (ret == 0 && (lst->str)[0] != '\0')
	{
		(*line = ft_strdup(lst->str)) ? ft_strdel(&bf) : 0;
		ft_strdel(&(lst->str));
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
	new = ft_find_fd(&head, fd);
	bf = ft_strnew(BUFF_SIZE);
	while (1)
	{
		if (new->str && !ft_strchr(new->str, '\n'))
		{
			ret = read(new->fd, bf, BUFF_SIZE);
			bf[ret] = '\0';
		}
		if (!new->str || (ret == 0 && (new->str)[0] == '\0'))
			break ;
		if (ret == -1)
			break ;
		if (new->str && ft_check(new, bf, line, ret))
			return (1);
	}
	ft_strdel(&bf);
        free(new);
	return (ret == -1 ? -1 : 0);
}
