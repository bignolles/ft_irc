/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 19:05:16 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 14:16:56 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netinet/in.h>
#include <libft.h>
#include <client.h>
#include <ft_error.h>

int		main(int argc, char **argv)
{
	t_env		env;

	init_env(&env);
	if (argc == 1)
		wait_for_connect(&env);
	else if (argc == 3)
	{
		get_opt(&env, argv[1], argv[2]);
		create_client(&env);
		run_client(&env);
	}
	else
	{
		usage(argv[0]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
