/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_accept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 11:03:10 by marene            #+#    #+#             */
/*   Updated: 2016/03/02 17:45:13 by marene           ###   ########.fr       */
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

static void		welcome_msg(t_env *env, int cs)
{
	ringbuff_write(env->fds[cs].buf_write,
			"\nWelcome to marene's IRC!\n\nHere's a list of all the channels:",
			RINGBUFF_CHUNK_SIZE);
	handle_channels(env, cs, NULL);
	ringbuff_write(env->fds[cs].buf_write,
		"\n\nAnd a list of all the commands you can use:",
		RINGBUFF_CHUNK_SIZE);
	handle_help(env, cs, NULL);
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
	env->fds[c_sock].type = FD_CLIENT;
	env->fds[c_sock].fct_read = client_read;
	env->fds[c_sock].fct_write = client_write;
	buff = ft_itoa(c_sock);
	env->fds[c_sock].nick = ft_strjoin("#", buff);
	welcome_msg(env, c_sock);
	free(buff);
}
