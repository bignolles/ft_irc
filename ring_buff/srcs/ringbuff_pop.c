/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:35:03 by marene            #+#    #+#             */
/*   Updated: 2016/03/21 16:37:46 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

void				ringbuff_pop_last(t_ringbuff *buff)
{
	if (buff->end > buff->start)
		buff->end -= 1;
}

void				ringbuff_pop_first(t_ringbuff *buff)
{
	if (buff->start < buff->end)
		buff->start += 1;
}
