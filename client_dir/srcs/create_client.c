/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 11:26:16 by marene            #+#    #+#             */
/*   Updated: 2014/11/02 17:09:19 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <netinet/in.h>
#include <client.h>
#include <ft_error.h>

void	create_client(t_env *env)
{
	struct protoent		*proto;
	struct sockaddr_in	cin;

	proto = tryptr(0, getprotobyname("tcp"), "tcp protocol");
	env->s_sock = tryint(-1, socket(PF_INET, SOCK_STREAM, proto->p_proto),
			"socket");
	cin.sin_family = AF_INET;
	cin.sin_port = htons(env->port);
	cin.sin_addr.s_addr = env->s_addr;
	tryint(-1, connect(env->s_sock, (const struct sockaddr *)&cin, sizeof(cin)),
			"connect");
}
