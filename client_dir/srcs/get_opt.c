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

#include <netinet/in.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_error.h>
#include <client.h>

void	get_opt(t_env *env, int argc, char **argv)
{
	if (argc != 3)
		usage(argv[0]);
	env->s_addr = tryint(INADDR_NONE, inet_addr(argv[1]), "invalid adress");
	env->port = tryint(0, ft_atoi(argv[2]), "invalid port");
}
