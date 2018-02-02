/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 21:16:35 by vsokolog          #+#    #+#             */
/*   Updated: 2018/01/19 21:16:36 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H
# include	<stdlib.h>
# include	<fcntl.h>
# include	<stdio.h> // DELETE ME, BEFORE PUSH ! ! !
# include	"./libft/libft.h"
# define	BUFF_SIZE 5

# define	RED "\x1b[31m" // DELETE ME, BEFORE PUSH ! ! !

int get_next_line(const int fd, char **line);

#endif