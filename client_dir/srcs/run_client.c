/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 18:23:21 by marene            #+#    #+#             */
/*   Updated: 2016/04/25 17:46:07 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <client.h>

void			run_client(t_env *env)
{
	int		select_nb;

	while (42)
	{
		select_nb = (env->s_sock > 0) ? env->s_sock + 1 : STDOUT_FILENO + 1;
		FD_ZERO(&env->fd_read);
		FD_ZERO(&env->fd_write);
		if (env->s_sock > 0)
			FD_SET(env->s_sock, &env->fd_read);
		if (env->s_sock > 0 && ringbuff_get_read_space(env->buf_write) > 0)
			FD_SET(env->s_sock, &env->fd_write);
		FD_SET(STDIN_FILENO, &env->fd_read);
		FD_SET(STDOUT_FILENO, &env->fd_write);
		if (env->fct_input != NULL)
			libcurses_check_input(env->screen, env->cursor);
		tryint(-1, select(select_nb, &env->fd_read, &env->fd_write, 0, 0),
			"select");
		check_fd(env);
	}
}
