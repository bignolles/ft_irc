/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_read_cpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:45:15 by marene            #+#    #+#             */
/*   Updated: 2016/02/26 19:29:56 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int			ringbuff_read_cpy(t_ringbuff *buff, char *chunk, int len)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = ringbuff_get_read_space(buff);
	while (i < len && i < max)
	{
		j = (buff->start + i) % buff->len;
		chunk[i] = buff->buff[j];
		++i;
	}
	return (i);
}
