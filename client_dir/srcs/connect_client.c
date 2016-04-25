/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_client.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 12:09:35 by marene            #+#    #+#             */
/*   Updated: 2016/04/25 17:42:57 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include "libft.h"
#include "ft_error.h"
#include "client.h"

int			connect_client(t_env *env)
{
	struct protoent		*proto;
	struct sockaddr_in	c;

	proto = tryptr(0, getprotobyname("tcp"), "tcp protocol");
	env->s_sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	env->fct_read = wait_read;
	env->fct_write = write_to_serv;
	env->fct_input = wait_for_connect;
	env->fct_output = read_from_serv_check;
	if (env->s_sock > 0 && env->port != -1 && env->s_addr != INADDR_NONE)
	{
		c.sin_family = AF_INET;
		c.sin_port = htons(env->port);
		c.sin_addr.s_addr = env->s_addr;
		if (connect(env->s_sock, (const struct sockaddr *)&c, sizeof(c)) != -1)
		{
			env->fct_input = NULL;
			return (CLI_OK);
		}
	}
	libcurses_add_input_by_name(env->screen,
		"No connection to server (/connect <host> <port number>)", BOX_CHAT);
	libcurses_refresh_panes(env->screen);
	return (CLI_FAIL);
}
