/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_srv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 14:41:38 by marene            #+#    #+#             */
/*   Updated: 2014/11/02 19:03:47 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_error.h>
#include <server.h>
#include <libft.h>

void	run_srv(t_env *env)
{
	while (42)
	{
		init_fd(env);
		ft_putendl("trying select");
		env->r = tryint(-1, select(env->max + 1, &env->fd_read, &env->fd_write,
				0, 0), "select");
		ft_putendl("select ok");
		check_fd(env);
	}
}
