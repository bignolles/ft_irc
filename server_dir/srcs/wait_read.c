/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:12:39 by marene            #+#    #+#             */
/*   Updated: 2016/03/08 17:10:43 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void		receive_ping(t_env *env, int cs)
{
	int		ret;
	char	buff[RINGBUFF_CHUNK_SIZE + 1];

	ret = recv(cs, buff, RINGBUFF_CHUNK_SIZE, 0);
	if (ret <= 0)
		end_connection(env, cs);
	else
	{
		env->fds[cs].wait_step += 1;
		ringbuff_write(env->fds[cs].buf_read, buff, ret);
	}
}

static void		check_ping(t_env *env, int cs)
{
	int		ret;
	char	*to_read;

	to_read = NULL;
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

void			wait_read(t_env *env, int cs)
{
	if (env->fds[cs].wait_step == 1)
		receive_ping(env, cs);
	if (env->fds[cs].wait_step == 2)
		check_ping(env, cs);
}
