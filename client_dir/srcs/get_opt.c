/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 16:30:40 by marene            #+#    #+#             */
/*   Updated: 2016/04/25 17:40:28 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <netdb.h>
#include <ft_error.h>
#include <client.h>

void	get_opt(t_env *env, char *hostname, char *port)
{
	struct hostent	*he;
	struct in_addr	**addr_list;

	if (port != NULL)
		env->port = ft_atoi(port);
	else
		env->port = -1;
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
		ringbuff_write(env->buf_read, "invalide hostname\n\r",
				RINGBUFF_CHUNK_SIZE);
}
