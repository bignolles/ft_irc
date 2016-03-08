/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:12:39 by marene            #+#    #+#             */
/*   Updated: 2016/03/08 14:05:01 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // A ENLEVER
#include "libft.h"
#include "server.h"

static void		welcome_msg(t_env *env, int cs)
{
	ringbuff_write(env->fds[cs].buf_write, "OK\n\r", 4);
	ringbuff_write(env->fds[cs].buf_write,
			"\nWelcome to marene's IRC!\n\nHere's a list of all the channels:",
			RINGBUFF_CHUNK_SIZE);
	handle_channels(env, cs, NULL);
	ringbuff_write(env->fds[cs].buf_write,
		"\n\nAnd a list of all the commands you can use:",
		RINGBUFF_CHUNK_SIZE);
	handle_help(env, cs, NULL);
	ringbuff_write(env->fds[cs].buf_write, "\n\r", 2);
}

void		wait_read(t_env *env, int cs)
{
	int		ret;
	char	buff[RINGBUFF_CHUNK_SIZE + 1];
	char	*to_read;

	to_read = NULL;
	if (env->fds[cs].wait_step == 1)
	{
		ret = recv(cs, buff, RINGBUFF_CHUNK_SIZE, 0);
		if (ret <= 0)
			end_connection(env, cs);
		else
		{
			env->fds[cs].wait_step += 1;
			ringbuff_write(env->fds[cs].buf_read, buff, ret);
		}
	}
	if (env->fds[cs].wait_step == 2)
	{
		ret = ringbuff_read_to_str(env->fds[cs].buf_read, &to_read, "\n\r");
	if (ret > 0)
		{
			if (ft_strncmp(env->fds[cs].ping, to_read, 5) == 0)
			{
				env->fds[cs].fct_read = client_read;
				env->fds[cs].fct_write = client_write;
				env->fds[cs].type = FD_CLIENT;
				welcome_msg(env, cs);
			}
			else
				end_connection(env, cs);
		}
	}
}
