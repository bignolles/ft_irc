/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 17:15:26 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 18:36:48 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <client.h>

#include <libft.h>

void	check_fd(t_env *env)
{
	if (FD_ISSET(1, &env->fd_read))
		read_from_client(env);
	if (FD_ISSET(env->s_sock, &env->fd_read))
		read_from_serv(env);
	if (FD_ISSET(env->s_sock, &env->fd_write))
		write_to_serv(env);
}
