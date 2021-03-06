/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:53:31 by marene            #+#    #+#             */
/*   Updated: 2016/05/05 14:53:41 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include "client.h"
#include "libft.h"
#include "ft_error.h"

void	init_env(t_env *env)
{
	env->port = -1;
	env->s_addr = INADDR_NONE;
	env->s_sock = -1;
	FD_ZERO(&env->fd_read);
	FD_ZERO(&env->fd_write);
	env->buf_write = ringbuff_construct();
	env->buf_read = ringbuff_construct();
	if (env->screen != NULL)
		libcurses_destruct_screen(&env->screen);
	ft_bzero(env->user_input, RINGBUFF_BUFF_SIZE + 1);
}
