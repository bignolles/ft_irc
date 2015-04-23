/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 12:54:38 by marene            #+#    #+#             */
/*   Updated: 2014/10/30 17:10:42 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <netinet/in.h>
#include <ft_error.h>
#include <server.h>

void	srv_create(t_env *env)
{
	int						s_sock;
	struct sockaddr_in		sin;
	struct protoent			*prot;

	prot = (struct protoent *)tryptr(NULL, getprotobyname("tcp"), "protocol");
	s_sock = tryint(-1, socket(PF_INET, SOCK_STREAM, prot->p_proto), "socket");
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(env->port);
	tryint(-1, bind(s_sock, (struct sockaddr *)&sin, sizeof(sin)), "bind");
	tryint(-1, listen(s_sock, QUEUE_SIZE), "listen");
	env->fds[s_sock].type = FD_SERV;
	env->fds[s_sock].fct_read = srv_accept;
}
