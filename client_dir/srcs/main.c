/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 19:05:16 by marene            #+#    #+#             */
/*   Updated: 2016/03/28 18:20:15 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netinet/in.h>
#include <libft.h>
#include <client.h>
#include <ft_error.h>

int		main(int argc, char **argv)
{
	t_env		env;

	env.screen = NULL;
	init_env(&env);
	setup_curses(&env);
	if (argc != 3)
		get_opt(&env, NULL, NULL);
	else
		get_opt(&env, argv[1], argv[2]);
	create_client(&env);
	run_client(&env);
	return (EXIT_SUCCESS);
}
