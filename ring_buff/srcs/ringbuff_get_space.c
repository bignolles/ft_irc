/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_get_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:23:25 by marene            #+#    #+#             */
/*   Updated: 2016/02/29 19:27:37 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int		ringbuff_get_write_space(t_ringbuff *buff)
{
	int		free_space;

	if (buff->start > buff->end)
		free_space = buff->start - buff->end;
	else if (buff->start < buff->end)
		free_space = buff->len - (buff->end - buff->start);
	else
		free_space = buff->len;
	return (free_space);
}

int		ringbuff_get_read_space(t_ringbuff *buff)
{
	int		read_size;

	if (buff->start < buff->end)
		read_size = buff->end - buff->start;
	else if (buff->start > buff->end)
		read_size = buff->len - (buff->start - buff->end);
	else
		read_size = 0;
	return (read_size);
}
