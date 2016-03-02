/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 12:38:55 by marene            #+#    #+#             */
/*   Updated: 2016/03/02 17:43:23 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "server.h"

void	clean_fd(t_fd *fd)
{
	fd->type = FD_FREE;
	fd->chan = DEFAULT_CHAN;
	fd->fct_read = NULL;
	fd->fct_write = NULL;
	ringbuff_destruct(&(fd->buf_read));
	ringbuff_destruct(&(fd->buf_write));
	fd->buf_read = ringbuff_construct();
	fd->buf_write = ringbuff_construct();
	fd->nick = NULL;
}
