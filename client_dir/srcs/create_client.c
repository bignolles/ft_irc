/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 11:26:16 by marene            #+#    #+#             */
/*   Updated: 2016/03/28 18:17:24 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <client.h>
#include <ft_error.h>
#include <libft.h>

void	create_client(t_env *env)
{
	struct protoent		*proto;
	struct sockaddr_in	cin;

	proto = tryptr(0, getprotobyname("tcp"), "tcp protocol");
	env->s_sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	env->fct_read = wait_read;
	env->fct_write = write_to_serv;
	env->fct_input = wait_for_connect;
	env->fct_output = read_from_serv_check;
	if (env->s_sock > 0 && env->port != -1)
	{
		cin.sin_family = AF_INET;
		cin.sin_port = htons(env->port);
		cin.sin_addr.s_addr = env->s_addr;
		if (connect(env->s_sock, (const struct sockaddr *)&cin, sizeof(cin)) != -1)
		{
			env->fct_read = wait_read;
			env->fct_write = write_to_serv;
			env->fct_input = NULL;
			env->fct_output = read_from_serv_check;
			return ;
		}
	}
	libcurses_add_input_by_name(env->screen, "No connection to server (/connect <host> <port number>)", BOX_CHAT);
	libcurses_refresh_panes(env->screen);
}
