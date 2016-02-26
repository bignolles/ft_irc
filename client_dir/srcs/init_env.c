/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 16:11:56 by marene            #+#    #+#             */
/*   Updated: 2016/02/26 17:01:26 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include <client.h>
#include <ft_error.h>

void	init_env(t_env *env)
{
	env->port = -1;
	env->s_addr = INADDR_NONE;
	env->s_sock = -1;
	FD_ZERO(&env->fd_read);
	FD_ZERO(&env->fd_write);
	env->buff_write = ringbuff_construct();
	env->buff_read = ringbuff_construct();
}
