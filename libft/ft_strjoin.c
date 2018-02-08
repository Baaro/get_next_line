/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:56:07 by vsokolog          #+#    #+#             */
/*   Updated: 2017/11/23 11:56:08 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (!(t = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*t))))
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		t[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		t[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	t[ft_strlen(s1) + i] = '\0';
	return (t);
}
