/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_write_cpy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:59:35 by marene            #+#    #+#             */
/*   Updated: 2016/03/02 17:22:32 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int		ringbuff_write_cpy(t_ringbuff *buff, char *chunk, int len)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = ringbuff_get_write_space(buff);
	while (i < len && i < max && chunk[i])
	{
		j = (buff->end + i) % buff->len;
		buff->buff[j] = chunk[i];
		++i;
	}
	return (i);
}
