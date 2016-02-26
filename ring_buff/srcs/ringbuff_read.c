/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:21:12 by marene            #+#    #+#             */
/*   Updated: 2016/02/26 19:38:28 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int		ringbuff_read(t_ringbuff *buff, char *chunk, int len)
{
	int		read_size;
	int		ret;

	ret = ringbuff_read_cpy(buff, chunk, len);
	buff->start = (buff->start + ret) % buff->len;
	return (ret);
}
