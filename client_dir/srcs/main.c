/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 19:05:16 by marene            #+#    #+#             */
/*   Updated: 2016/04/01 16:41:39 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <netinet/in.h>
#include <libft.h>
#include <client.h>
#include <ft_error.h>

int		main(int argc, char **argv)
{
	t_env		*env;

	env = create_env(argc, argv);
	if (env != NULL)
	{
		connect_client(env);
		run_client(env);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_putstr("Some unexpected error occured, and ");
		ft_putstr(argv[0]);
		ft_putendl(" failed to launch.");
		return (EXIT_FAILURE);
	}
}
