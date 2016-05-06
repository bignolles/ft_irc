/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:02:20 by marene            #+#    #+#             */
/*   Updated: 2016/05/06 14:43:48 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ringbuff.h"

static int			compare_start_end(int i, t_ringbuff *buff)
{
	return (i >= buff->start && i < buff->end);
}

static int			compare_end_start(int i, t_ringbuff *buff)
{
	return (buff->end != buff->start && (i < buff->end || i >= buff->start));
}

static t_cmp_fct	get_cmp(t_ringbuff *buff)
{
	if (buff->start < buff->end)
		return (compare_start_end);
	else
		return (compare_end_start);
}

static void			ft_putchar_escape(char c)
{
	if (c == '\0')
		return ;
	else if (c == '\n')
		write(1, "\\n", 2);
	else if (c == '\t')
		write(1, "\\t", 2);
	else if (c == '\r')
		write(1, "\\r", 2);
	else
		write(1, &c, 1);
}

void				ringbuff_dump(t_ringbuff *buff)
{
	int			i;
	t_cmp_fct	cmp;

	i = 0;
	cmp = get_cmp(buff);
	while (i < buff->len)
	{
		if (cmp(i, buff))
			write(1, RINGBUFF_GREEN, 6);
		ft_putchar_escape(buff->buff[i]);
		write(1, RINGBUFF_DEFAULT, 6);
		++i;
	}
	write(1, "\n", 1);
}
