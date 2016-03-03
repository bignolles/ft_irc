/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 11:16:22 by marene            #+#    #+#             */
/*   Updated: 2016/03/03 15:13:49 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <libft.h>
#include <ft_error.h>
#include <server.h>

void	client_write(t_env *env, int cs)
{
	int		ret;
	int		len;
	char	buff[RINGBUFF_CHUNK_SIZE + 1];

	ft_putendl("client_write");
	buff[RINGBUFF_CHUNK_SIZE] = '\0';
	len = ringbuff_read_cpy(env->fds[cs].buf_write, buff, RINGBUFF_CHUNK_SIZE);
	buff[len] = '\0';
	ft_putstr("\t-> ");
	ft_putendl(buff);
	ret = tryint(-1, send(cs, buff, len, 0), "send");
	ringbuff_read(env->fds[cs].buf_write, buff, len);
}
