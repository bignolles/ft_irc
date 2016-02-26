/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_get_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:23:25 by marene            #+#    #+#             */
/*   Updated: 2016/02/26 16:25:16 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int		ringbuff_get_write_space(t_ringbuff *buff)
{
	int		free_space;

	if (buff->start > buff->end)
		free_space = buff->len - (buff->start - buff->end);
	else
		free_space = buff->end - buff->start;
	return (free_space);
}

int		ringbuff_get_read_space(t_ringbuff *buff)
{
	int		read_size;

	if (buff->start < buff->end)
		read_size = buff->len - (buff->end - buff->start);
	else
		read_size = buff->start - buff->end;
	return (read_size);
}
