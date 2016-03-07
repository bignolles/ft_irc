/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 19:16:39 by marene            #+#    #+#             */
/*   Updated: 2016/03/07 19:41:01 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # include <stdio.h> // <- A ENLEVER APRES

#include "libft.h"
#include "ft_error.h"
#include "client.h"

void		wait_read(t_env *env)
{
	char	buff[RINGBUFF_CHUNK_SIZE + 1];
	char	*to_read;
	int		ret;

	to_read = NULL;
	ft_putendl("wait_read");
	ret = recv(env->s_sock, buff, RINGBUFF_CHUNK_SIZE, 0);
	if (ret > 0)
	{
		buff[ret] = '\0';
		ft_putendl(buff);
		ringbuff_write(env->buf_read, buff, ret);
		if (ringbuff_read_to_str(env->buf_read, &to_read, "\n\r") > 0)
		{
			if (ft_strequ(to_read, "OK\n\r"))
			{
				env->fct_read = read_from_serv;
				env->fct_input = read_from_client;
			}
			else
			{
				ringbuff_write(env->buf_write, to_read, ft_strlen(to_read));
				printf("%d\n", ringbuff_get_read_space(env->buf_write));
				ringbuff_dump(env->buf_write);
			}
		}
	}
	else
		exit(42);
}
