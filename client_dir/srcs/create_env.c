/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 11:26:16 by marene            #+#    #+#             */
/*   Updated: 2016/05/05 16:39:47 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netdb.h>
#include <client.h>
#include <ft_error.h>
#include <libft.h>

static void		opt_preset(int ac, char **av, char **args)
{
	if (ac >= 2)
	{
		args[1] = ft_strdup(av[1]);
		if (ac == 3)
			args[2] = ft_strdup(av[2]);
		else
			args[2] = ft_strdup("4242");
	}
	else
	{
		args[1] = ft_strdup("localhost");
		args[2] = ft_strdup("4242");
	}
}

t_env			*create_env(int ac, char **av)
{
	t_env		*env;
	char		*args[3];

	env = NULL;
	args[0] = NULL;
	if (ac <= 3)
	{
		env = malloc(sizeof(t_env));
		if (env != NULL)
		{
			env->screen = NULL;
			init_env(env);
			setup_curses(env);
			opt_preset(ac, av, args);
			get_opt(env, args);
		}
	}
	return (env);
}
