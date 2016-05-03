/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 16:30:40 by marene            #+#    #+#             */
/*   Updated: 2016/04/29 10:42:33 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <netdb.h>
#include <ft_error.h>
#include <client.h>

static int		get_port_nb(char *port)
{
	int		i;
	int		port_nb;

	i = 0;
	port_nb = -1;
	if (port != NULL)
	{
		while (port[i])
		{
			if (!ft_isdigit(port[i]))
				return (port_nb);
			++i;
		}
		port_nb = ft_atoi(port);
	}
	return (port_nb);
}

void			get_opt(t_env *env, char *hostname, char *port)
{
	struct hostent	*he;
	struct in_addr	**addr_list;

	env->port = get_port_nb(port);
	if (hostname != NULL && (he = gethostbyname(hostname)) != NULL)
	{
		addr_list = (struct in_addr **)he->h_addr_list;
		env->s_addr = inet_addr(inet_ntoa(**addr_list));
	}
	else if (hostname != NULL)
	{
		env->s_addr = inet_addr(hostname);
	}
	if (env->s_addr == INADDR_NONE)
		ringbuff_write(env->buf_read, "invalid hostname\n\r",
				RINGBUFF_CHUNK_SIZE);
	if (env->port == -1)
		ringbuff_write(env->buf_read, "invalid port\n\r",
				RINGBUFF_CHUNK_SIZE);
}
