/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:19:23 by vsokolog          #+#    #+#             */
/*   Updated: 2017/12/03 14:43:11 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long int	nbr;
	int					nums;
	int					negative;

	i = 0;
	nbr = 0;
	nums = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == ' ') ||
		(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		if ((nbr = (nbr * 10) + (int)str[i] - '0'))
			nums++;
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}
