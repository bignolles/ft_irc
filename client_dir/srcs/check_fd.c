/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 17:15:26 by marene            #+#    #+#             */
/*   Updated: 2016/04/25 17:47:32 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <client.h>

void	check_fd(t_env *env)
{
	if (FD_ISSET(STDIN_FILENO, &env->fd_read) && env->fct_input != NULL)
		env->fct_input(env);
	if (env->s_sock > 0 && FD_ISSET(env->s_sock, &env->fd_read))
		env->fct_read(env);
	if (FD_ISSET(STDOUT_FILENO, &env->fd_write)
			&& ringbuff_get_read_space(env->buf_read) > 0)
		env->fct_output(env);
	if (env->s_sock > 0 && FD_ISSET(env->s_sock, &env->fd_write))
		env->fct_write(env);
}
