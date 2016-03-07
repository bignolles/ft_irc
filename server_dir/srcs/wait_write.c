/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:59:17 by marene            #+#    #+#             */
/*   Updated: 2016/03/07 19:05:58 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "libft.h"
#include "ft_error.h"
#include "server.h"

static int	send_ping(t_env *env, int cs)
{
	char	*buffer;
	int		ret;
	int		len;

	buffer = NULL;
	len = ringbuff_read_to_str(env->fds[cs].buf_write, &buffer, "\n\r");
	buffer[len] = '\0';
	ret = tryint(-1, send(cs, buffer, len, 0), "send");
	ringbuff_read(env->fds[cs].buf_write, buffer, ret);
	if (ringbuff_get_read_space(env->fds[cs].buf_write) == 0)
		return (1);
	return (0);
}

void		wait_write(t_env *env, int cs)
{
	if (env->fds[cs].wait_step == 0)
	{
		if (send_ping(env, cs))
			env->fds[cs].wait_step += 1;
	}
}
