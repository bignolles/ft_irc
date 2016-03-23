/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 19:01:05 by marene            #+#    #+#             */
/*   Updated: 2016/03/23 18:52:06 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "server.h"

void		end_connection(t_env *env, int cs)
{
	char	*buff;
	char	*tmp;
	char	*cs_str;

	cs_str = ft_itoa(cs);
	buff = (env->fds[cs].nick == NULL) ? ft_strjoin("#", cs_str) :
		ft_strdup(env->fds[cs].nick);
	tmp = ft_strjoin(buff, " has gone away\n\r");
	distribute_to_peers(env, cs, tmp);
	disp_client_away(env, cs);
	close(cs);
	free(env->fds[cs].nick);
	clean_fd(&env->fds[cs]);
	free(tmp);
	free(buff);
	free(cs_str);
}
