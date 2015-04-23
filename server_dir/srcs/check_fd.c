/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 11:45:40 by marene            #+#    #+#             */
/*   Updated: 2014/10/31 15:08:14 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void	check_fd(t_env *env)
{
	int		i;
	int		dec_r;

	i = 0;
	while (i < env->max_fd && env->r > 0)
	{
		dec_r = 0;
		if (FD_ISSET(i, &env->fd_read))
		{
			env->fds[i].fct_read(env, i);
			dec_r = 1;
		}
		if (FD_ISSET(i, &env->fd_write))
		{
			env->fds[i].fct_write(env, i);
			dec_r = 1;
		}
		if (dec_r)
			--env->r;
		++i;
	}
}
