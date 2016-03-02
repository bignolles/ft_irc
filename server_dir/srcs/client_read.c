/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 17:12:58 by marene            #+#    #+#             */
/*   Updated: 2016/03/02 18:50:04 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_error.h>
#include <server.h>

static void		zero_buff(char *buff, int start)
{
	int		i;

	i = start;
	while (i < RINGBUFF_CHUNK_SIZE)
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

/*
static void		add_input(t_env *env, char *cmd_ret, int i)
{
	char	*buff;

	buff = env->fds[i].buf_write;
	env->fds[i].buf_write = ft_strjoin(buff, "\n");
	free(buff);
	buff = env->fds[i].buf_write;
	env->fds[i].buf_write = ft_strjoin(buff, cmd_ret);
	free(buff);
}
*/

void			client_read(t_env *env, int cs)
{
	int		ret;
	int		i;
	char	*cmd_ret;
	char	*to_read;
	char	buff[RINGBUFF_CHUNK_SIZE + 1];

	buff[RINGBUFF_CHUNK_SIZE] = '\0';
	ret = recv(cs, buff, RINGBUFF_CHUNK_SIZE, 0);
	buff[ret] = '\0';
	if (ret <= 0)
		end_connection(env, cs);
	else
	{
		i = 0;
		zero_buff(buff, ret); // Pas sur que ce soit utile a present
		ringbuff_write(env->fds[cs].buf_read, buff, ret);
		ret = ringbuff_read_to_str(env->fds[cs].buf_read, &to_read, "\n\r");
		if (ret > 0)
		{
			cmd_ret = get_client_input(env, cs, to_read);
			while (i < env->max_fd && env->fds[cs].chan != 0)
			{
				if (env->fds[i].type == FD_CLIENT && i != cs &&
						env->fds[i].chan == env->fds[cs].chan
						&& cmd_ret != NULL)
					ringbuff_write(env->fds[i].buf_write, cmd_ret, ft_strlen(cmd_ret));
					//add_input(env, cmd_ret, i);
				++i;
			}
			free(cmd_ret);
		}
	}
}
