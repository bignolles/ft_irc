/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_serv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 19:21:42 by marene            #+#    #+#             */
/*   Updated: 2016/03/24 17:46:51 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <client.h>

void	read_from_serv(t_env *env)
{
	char	buff[RINGBUFF_CHUNK_SIZE + 1];
	int		ret;

	ret = recv(env->s_sock, buff, RINGBUFF_CHUNK_SIZE, 0);
	if (ret <= 0)
	{
		libcurses_add_input_by_name(env->screen, "Lost connection to server", BOX_CHAT);
		env->fct_input = wait_for_connect;
		env->s_sock = -1;
		/*
		env_delete(env);
		init_env(env);
		wait_for_connect(env);
		*/
	}
	else
	{
		buff[ret] = '\0';
		ringbuff_write(env->buf_read, buff, ret);
		read_from_serv_check(env);
	}
}
