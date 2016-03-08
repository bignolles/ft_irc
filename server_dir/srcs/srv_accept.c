/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_accept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 11:03:10 by marene            #+#    #+#             */
/*   Updated: 2016/03/08 12:05:31 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netinet/in.h>
#include <arpa/inet.h>
#include <libft.h>
#include <ft_error.h>
#include <server.h>

/*
** int s param is the server's socket
*/

static void		setup_ping(t_env *env, int cs)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		env->fds[cs].ping[i] = '0' + (rand() % 10);
		++i;
	}
}

void			srv_accept(t_env *env, int s)
{
	int						c_sock;
	struct sockaddr_in		c_sin;
	socklen_t				len;
	char					*buff;

	len = sizeof(c_sin);
	c_sock = tryint(-1, accept(s, (t_sockaddr *)&c_sin, &len), "accept");
	disp_new_client(c_sock, c_sin);
	clean_fd(&env->fds[c_sock]);
	env->fds[c_sock].type = FD_CLIENT_WAITING;
	env->fds[c_sock].fct_read = wait_read;
	env->fds[c_sock].fct_write = wait_write;
	buff = ft_itoa(c_sock);
	env->fds[c_sock].nick = ft_strjoin("#", buff);
	setup_ping(env, c_sock);
	ringbuff_write(env->fds[c_sock].buf_write, env->fds[c_sock].ping, 5);
	ringbuff_write(env->fds[c_sock].buf_write, "\n\r", 2);
//	welcome_msg(env, c_sock);
	free(buff);
}
