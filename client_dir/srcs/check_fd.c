/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 17:15:26 by marene            #+#    #+#             */
/*   Updated: 2016/03/08 14:58:39 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <client.h>

#include <libft.h>

void	check_fd(t_env *env)
{
	if (FD_ISSET(1, &env->fd_read) && env->fct_input != NULL) // line 29 of client_dir/srcs/run_client.c make the second part of condition redundant
		env->fct_input(env);
	else if (FD_ISSET(env->s_sock, &env->fd_read))
		env->fct_read(env);
	if (FD_ISSET(env->s_sock, &env->fd_write))
		env->fct_write(env);
}
