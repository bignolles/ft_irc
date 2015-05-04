/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 17:15:26 by marene            #+#    #+#             */
/*   Updated: 2015/05/04 16:16:28 by marene           ###   ########.fr       */
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
	else if (FD_ISSET(env->s_sock, &env->fd_read))
		read_from_serv(env);
	if (FD_ISSET(env->s_sock, &env->fd_write))
		write_to_serv(env);
}
