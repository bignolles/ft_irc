/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 11:26:16 by marene            #+#    #+#             */
/*   Updated: 2016/04/01 16:41:30 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <client.h>
#include <ft_error.h>
#include <libft.h>

static void		opt_preset(int ac, char **av, char **host, char **port)
{
	if (ac >= 2)
	{
		*host = ft_strdup(av[1]);
		if (ac == 3)
			*port = ft_strdup(av[2]);
		else
			*port = ft_strdup("4242");
	}
	else
	{
		*host = ft_strdup("localhost");
		*port = ft_strdup("4242");
	}
}

t_env			*create_env(int ac, char **av)
{
	t_env		*env;
	char		*host;
	char		*port;

	env = NULL;
	if (ac <= 3)
	{
		env = malloc(sizeof(t_env));
		if (env != NULL)
		{
			env->screen = NULL;
			init_env(env);
			setup_curses(env);
			opt_preset(ac, av, &host, &port);
			get_opt(env, host, port);
		}
	}
	return (env);
}
