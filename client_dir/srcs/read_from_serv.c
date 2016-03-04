/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_serv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 19:21:42 by marene            #+#    #+#             */
/*   Updated: 2016/03/04 17:27:57 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <client.h>

void	read_from_serv(t_env *env)
{
	char	buff[RINGBUFF_CHUNK_SIZE + 1];
	char	*to_print;
	int		ret;

	to_print = NULL;
	ret = recv(env->s_sock, buff, RINGBUFF_CHUNK_SIZE, 0);
	if (ret <= 0)
	{
		ft_putendl("Disconnected from server");
		env_delete(env);
		init_env(env);
		wait_for_connect(env);
	}
	else
	{
		buff[ret] = '\0';
		ringbuff_write(env->buf_read, buff, ret);
		ret = ringbuff_read_to_str(env->buf_read, &to_print, IRC_END);
		if (ret > 0)
		{
			if (ft_strlen(to_print) > 2) // if there is something else than a mere "\n\r" to print. Find a cleaner way to achieve it server side by
				// avoiding sending bare "\n\r" packets of data
			{
				write(1, to_print, ret - 2);
				ft_putchar('\n');
			}
			ringbuff_read(env->buf_read, to_print, ret);
		}
		else
		{
			ft_putendl("== NOPE ==");
			ringbuff_dump(env->buf_read);
		}
	}
}
