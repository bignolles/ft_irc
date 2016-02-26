/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_destruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:47:51 by marene            #+#    #+#             */
/*   Updated: 2016/02/26 17:49:47 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ringbuff.h"

void		ringbuff_destruct(t_ringbuff **buff)
{
	free((*buff)->buff);
	*buff = NULL;
}
