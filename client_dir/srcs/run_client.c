/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 18:23:21 by marene            #+#    #+#             */
/*   Updated: 2016/03/21 15:26:17 by marene           ###   ########.fr       */
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
		if (ringbuff_get_read_space(env->buf_write) > 0)
		{
			FD_SET(env->s_sock, &env->fd_write);
		}
		FD_SET(STDIN_FILENO, &env->fd_read);
		FD_SET(STDOUT_FILENO, &env->fd_write);
		if (env->fct_input != NULL)
		{
			if (libcurses_check_input(env->screen, env->cursor) == LIBCURSES_NOK)
				exit(42); // TODO : Find appropriate way to deal with check_input errors, rather than 'exit'
		}
		tryint(-1, select(env->s_sock + 1, &env->fd_read, &env->fd_write, 0, 0),
				"select");
		check_fd(env);
	}
}
