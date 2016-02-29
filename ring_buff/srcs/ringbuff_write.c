/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:01:47 by marene            #+#    #+#             */
/*   Updated: 2016/02/29 18:42:01 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int			ringbuff_write(t_ringbuff *buff, char *chunk, int len)
{
	if (ringbuff_has_space(buff, len))
	{
		ringbuff_write_cpy(buff, chunk, len);
		buff->end = (buff->end + len) % buff->len;
		return (RING_OK);
	}
	return (RING_NOK);
}
