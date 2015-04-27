/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 17:12:58 by marene            #+#    #+#             */
/*   Updated: 2015/04/22 19:35:43 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_error.h>
#include <server.h>

# include <stdio.h>

static void		zero_buff(char *buff, int start)
{
	int		i;

	i = start;
	while (i < BUF_SIZE)
	{
		buff[i] = '\0';
		++i;
	}
}

static void		end_connection(t_env *env, int cs)
{
	disp_client_away(env, cs);
	close(cs);
	free(env->fds[cs].buf_write);
	free(env->fds[cs].nick);
	clean_fd(&env->fds[cs]);
}

static void		add_input(t_env *env, char *cmd_ret, int i)
{
	char	*buff;

	buff = env->fds[i].buf_write;
	env->fds[i].buf_write = ft_strjoin(buff, "\n");
	free(buff);
	buff = env->fds[i].buf_write;
	env->fds[i].buf_write = ft_strjoin(buff, ft_strdup(cmd_ret));
	free(buff);
}

void			client_read(t_env *env, int cs)
{
	int		ret;
	int		i;
	char	*cmd_ret;

	ret = recv(cs, env->fds[cs].buf_read, BUF_SIZE, 0);
	if (ret <= 0)
		end_connection(env, cs);
	else
	{
		i = 0;
		zero_buff(env->fds[cs].buf_read, ret);
		cmd_ret = get_client_input(env, cs, env->fds[cs].buf_read);
		while (i < env->max_fd && env->fds[cs].chan != 0)
		{
			if (env->fds[i].type == FD_CLIENT && i != cs &&
					env->fds[i].chan == env->fds[cs].chan)
				add_input(env, cmd_ret, i);
			++i;
		}
		free(cmd_ret);
	}
}