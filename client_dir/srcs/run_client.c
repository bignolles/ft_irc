/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 18:23:21 by marene            #+#    #+#             */
/*   Updated: 2015/04/30 17:27:59 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <client.h>

void			run_client(t_env *env)
{
	while (42)
	{
		FD_ZERO(&env->fd_read);
		FD_ZERO(&env->fd_write);
		FD_SET(env->s_sock, &env->fd_read);
		if (ft_strlen(env->buf_read) > 0)
			FD_SET(env->s_sock, &env->fd_write);
		else
		{
			ft_putstr(PROMPT);
			FD_SET(1, &env->fd_read);
		}
		tryint(-1, select(env->s_sock + 1, &env->fd_read, &env->fd_write, 0, 0),
				"select");
		check_fd(env);
	}
}
