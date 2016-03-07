/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:12:39 by marene            #+#    #+#             */
/*   Updated: 2016/03/07 19:44:26 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // A ENLEVER
#include "libft.h"
#include "server.h"

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
				ringbuff_write(env->fds[cs].buf_write, "OK\n\r", 4);
				env->fds[cs].fct_read = client_read;
				env->fds[cs].fct_write = client_write;
			}
			else
			{
				printf("ping : [%s](%zu) to_read : [%s](%zu)\n", env->fds[cs].ping, ft_strlen(env->fds[cs].ping), to_read, ft_strlen(to_read));
				ft_putendl("NOOOOOOO");
				end_connection(env, cs);
			}
		}
	}
}
