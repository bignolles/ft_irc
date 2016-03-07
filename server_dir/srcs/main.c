/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 11:21:12 by marene            #+#    #+#             */
/*   Updated: 2016/03/07 14:08:51 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <time.h>
#include <stdlib.h>

t_cmd		g_cmd_table[CMD_NB] = {
	{"/nick", ": Change nickname", handle_nick},
	{"/join", ": join or create channel", handle_join},
	{"/who", ": See who is connected to the current channel", handle_who},
	{"/msg", ": Send a private message to a user", handle_msg},
	{"/channels",
		": List all channels, and how many users are connected to them",
		handle_channels},
	{"/find", ": Find to what chan an user is connected", handle_find},
	{"/where", ": Display what channel you are connected to", handle_where},
	{"/help", ": Display help", handle_help},
};

int			main(int argc, char **argv)
{
	t_env	env;

	srand(time(NULL));
	init_env(&env);
	get_opt(&env, argc, argv);
	srv_create(&env);
	run_srv(&env);
	return (EXIT_SUCCESS);
}
