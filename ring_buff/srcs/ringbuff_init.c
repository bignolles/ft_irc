/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:27:23 by marene            #+#    #+#             */
/*   Updated: 2016/03/02 13:56:18 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ringbuff.h"

t_ringbuff		*ringbuff_construct(void)
{
	t_ringbuff	*ret;
	int			i;

	ret = malloc(sizeof(t_ringbuff));
	if (ret != NULL)
	{
		ret->buff = malloc(sizeof(char) * (RINGBUFF_BUFF_SIZE + 1));
		if (ret->buff == NULL)
		{
			free(ret);
			ret = NULL;
		}
		else
		{
			// Modify this later
			ret->start = 0;
			ret->end = 0;
			ret->len = RINGBUFF_BUFF_SIZE;
			ret->errno = NO_ERROR;
			i = 0;
			while (i < ret->len)
			{
				ret->buff[i] = '\0';
				++i;
			}
		}
	}
	return (ret);
}
