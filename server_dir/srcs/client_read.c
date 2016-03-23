/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 17:12:58 by marene            #+#    #+#             */
/*   Updated: 2016/03/23 18:48:37 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_error.h>
#include <server.h>

void			client_read(t_env *env, int cs)
{
	int		ret;
	char	*cmd_ret;
	char	*to_read;
	char	buff[RINGBUFF_CHUNK_SIZE + 1];

	buff[RINGBUFF_CHUNK_SIZE] = '\0';
	ret = recv(cs, buff, RINGBUFF_CHUNK_SIZE, 0);
	buff[ret] = '\0';
	if (ret <= 0)
		end_connection(env, cs);
	else
	{
		ringbuff_write(env->fds[cs].buf_read, buff, ret);
		ret = ringbuff_read_to_str(env->fds[cs].buf_read, &to_read, "\n\r");
		if (ret > 2)
		{
			to_read[ret - 1] = '\0';
			to_read[ret - 2] = '\0';
			cmd_ret = get_client_input(env, cs, to_read);
			distribute_to_peers(env, cs, cmd_ret);
			free(cmd_ret);
		}
	}
}
