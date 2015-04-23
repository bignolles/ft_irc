/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 12:47:18 by marene            #+#    #+#             */
/*   Updated: 2014/10/30 11:00:44 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <server.h>
#include <stdlib.h>

void	get_opt(t_env *env, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr(argv[0]);
		ft_putendl(SERV_USAGE);
		exit(EXIT_FAILURE);
	}
	env->port = ft_atoi(argv[1]);
}
