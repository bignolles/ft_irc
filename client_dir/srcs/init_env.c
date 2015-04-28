/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 16:11:56 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 14:01:05 by marene           ###   ########.fr       */
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
	env->buf_read = NULL;
	env->buf_write = NULL;
}
