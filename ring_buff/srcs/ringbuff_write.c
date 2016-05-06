/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:01:47 by marene            #+#    #+#             */
/*   Updated: 2016/05/06 14:42:34 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int			ringbuff_write(t_ringbuff *buff, char *chunk, int len)
{
	int		ret;

	if (ringbuff_has_space(buff, len))
	{
		ret = ringbuff_write_cpy(buff, chunk, len);
		buff->end = (buff->end + ret) % buff->len;
		return (RING_OK);
	}
	return (RING_NOK);
}
