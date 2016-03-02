/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:01:47 by marene            #+#    #+#             */
/*   Updated: 2016/03/02 14:11:05 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int			ringbuff_write(t_ringbuff *buff, char *chunk, int len)
{
	if (ringbuff_has_space(buff, len))
	{
		if (ringbuff_write_cpy(buff, chunk, len) != len)
			return (RING_NOK);
		buff->end = (buff->end + len) % buff->len;
		return (RING_OK);
	}
	return (RING_NOK);
}
