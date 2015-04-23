/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_accept.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 11:03:10 by marene            #+#    #+#             */
/*   Updated: 2014/11/02 17:48:10 by marene           ###   ########.fr       */
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

void	srv_accept(t_env *env, int s)
{
	int						c_sock;
	struct sockaddr_in		c_sin;
	socklen_t				len;
	char					*buff;

	len = sizeof(c_sin);
	c_sock = tryint(-1, accept(s, (t_sockaddr *)&c_sin, &len), "accept");
	disp_new_client(c_sock, c_sin);
	free(env->fds[c_sock].buf_write);
	clean_fd(&env->fds[c_sock]);
	env->fds[c_sock].type = FD_CLIENT;
	env->fds[c_sock].fct_read = client_read;
	env->fds[c_sock].fct_write = client_write;
	buff = ft_itoa(c_sock);
	env->fds[c_sock].nick = ft_strjoin("#", buff);
	free(buff);
}
