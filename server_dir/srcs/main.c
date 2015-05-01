/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 11:21:12 by marene            #+#    #+#             */
/*   Updated: 2015/05/01 17:19:11 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <stdlib.h>

t_cmd		g_cmd_table[CMD_NB] = {
	{"/nick \0", handle_nick},
	{"/join \0", handle_join},
	{"/who \0", handle_who},
	{"/msg \0", handle_msg},
	{"/channels \0", handle_channels},
};

int			main(int argc, char **argv)
{
	t_env	env;

	init_env(&env);
	get_opt(&env, argc, argv);
	srv_create(&env);
	run_srv(&env);
	return (EXIT_SUCCESS);
}
