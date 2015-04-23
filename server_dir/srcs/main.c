/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 11:21:12 by marene            #+#    #+#             */
/*   Updated: 2014/11/02 19:09:59 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <stdlib.h>

t_cmd		g_cmd_table[CMD_NB] =
{{"/NICK \0", handle_nick}};

int			main(int argc, char **argv)
{
	t_env	env;

	init_env(&env);
	get_opt(&env, argc, argv);
	srv_create(&env);
	run_srv(&env);
	return (EXIT_SUCCESS);
}
