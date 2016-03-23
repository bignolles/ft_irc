/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_to_peers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:48:46 by marene            #+#    #+#             */
/*   Updated: 2016/03/23 18:49:01 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server.h"

void		distribute_to_peers(t_env *env, int cs, char *cmd_ret)
{
	int		i;

	i = 0;
	ft_putstr("distribute : ");
	ft_putendl(cmd_ret);
	while (i < env->max_fd && env->fds[cs].chan != 0
			&& cmd_ret != NULL && ft_strlen(cmd_ret) > 0)
	{
		if (env->fds[i].type == FD_CLIENT && i != cs &&
				env->fds[i].chan == env->fds[cs].chan)
		{
			ringbuff_write(env->fds[i].buf_write, cmd_ret, ft_strlen(cmd_ret));
			ringbuff_write(env->fds[i].buf_write, "\n\r", 2);
		}
		++i;
	}
}
