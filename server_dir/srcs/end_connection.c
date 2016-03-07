/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 19:01:05 by marene            #+#    #+#             */
/*   Updated: 2016/03/07 19:06:56 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "server.h"

void		end_connection(t_env *env, int cs)
{
	disp_client_away(env, cs);
	close(cs);
	free(env->fds[cs].nick);
	clean_fd(&env->fds[cs]);
}
