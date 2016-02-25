/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circbuff_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:27:23 by marene            #+#    #+#             */
/*   Updated: 2016/02/25 16:30:33 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "circbuff.h"

t_circbuff		*circbuff_init(void)
{
	t_circbuff	*ret;

	ret = malloc(sizeof(t_circbuff));
	if (ret != NULL)
	{
		ret->buff = malloc(sizeof(char) * (CIRCBUFF_BUFF_SIZE + 1));
		if (ret->buff == NULL)
		{
			free(ret);
			ret = NULL;
		}
		else
		{
			// Modify this later
			ret->read = 0;
			ret->write = 0;
			ret->tmp = 0;
		}
	}
	return (ret);
}
