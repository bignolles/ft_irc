/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 16:30:40 by marene            #+#    #+#             */
/*   Updated: 2016/03/28 18:18:23 by marene           ###   ########.fr       */
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
		env->s_addr = tryint(INADDR_NONE, inet_addr(inet_ntoa(**addr_list)),
				"invalid hostname");
	}
	else if (hostname != NULL)
		env->s_addr = tryint(INADDR_NONE, inet_addr(hostname),
				"invalid adress");
	else
		env->port = -1;
}
