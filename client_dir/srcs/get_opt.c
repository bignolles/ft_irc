/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 16:30:40 by marene            #+#    #+#             */
/*   Updated: 2014/11/02 17:24:25 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <netdb.h>
#include <ft_error.h>
#include <client.h>

void	get_opt(t_env *env, int argc, char **argv)
{
	struct hostent	*he;
	struct in_addr	**addr_list;

	if (argc != 3)
		usage(argv[0]);
	if ((he = gethostbyname(argv[1])) != NULL)
	{
		addr_list = (struct in_addr **)he->h_addr_list;
		env->s_addr = tryint(INADDR_NONE, inet_addr(inet_ntoa(**addr_list)), "invalid hostname");
	}
	else
		env->s_addr = tryint(INADDR_NONE, inet_addr(argv[1]), "invalid adress");
	env->port = tryint(0, ft_atoi(argv[2]), "invalid port");
}
