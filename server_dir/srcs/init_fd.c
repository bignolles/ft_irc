/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 13:51:11 by marene            #+#    #+#             */
/*   Updated: 2016/03/02 17:45:57 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

void	init_fd(t_env *env)
{
	int		i;

	i = 0;
	env->max = 0;
	FD_ZERO(&env->fd_read);
	FD_ZERO(&env->fd_write);
	while (i < env->max_fd)
	{
		if (env->fds[i].type != FD_FREE)
		{
			FD_SET(i, &env->fd_read);
			if (ringbuff_get_read_space(env->fds[i].buf_write) > 0)
				FD_SET(i, &env->fd_write);
			env->max = MAX(env->max, i);
		}
		++i;
	}
}
