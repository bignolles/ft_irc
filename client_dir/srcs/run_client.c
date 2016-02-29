/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 18:23:21 by marene            #+#    #+#             */
/*   Updated: 2016/02/29 18:46:21 by marene           ###   ########.fr       */
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
		FD_SET(0, &env->fd_read);
		if (ringbuff_get_read_space(env->buf_write) > 0)
		{
			ft_putstr("env->buf_write : ");
			ft_putstr(ft_strtrim(env->buf_write->buff));
			ft_putstr(" (");
			ft_putnbr(env->buf_write->start);
			ft_putstr(" - ");
			ft_putnbr(env->buf_write->end);
			ft_putstr(" -> ");
			ft_putnbr(ringbuff_get_read_space(env->buf_write));
			ft_putendl(")");
			FD_SET(env->s_sock, &env->fd_write);
		}
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
