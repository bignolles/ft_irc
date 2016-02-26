/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_has_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:26:20 by marene            #+#    #+#             */
/*   Updated: 2016/02/26 16:28:52 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int		ringbuff_has_space(t_ringbuff *buff, int len)
{
	int		free_space;

	free_space = ringbuff_get_write_space(buff);
	return (len < free_space);
}
