/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_serv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 14:35:22 by marene            #+#    #+#             */
/*   Updated: 2016/03/02 16:43:58 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <client.h>

void	write_to_serv(t_env *env)
{
	int		ret;
	size_t	len;
	char	buff[RINGBUFF_CHUNK_SIZE + 1];

	len = ringbuff_read_cpy(env->buf_write, buff, RINGBUFF_CHUNK_SIZE);
	buff[len] = '\0';
	ret = tryint(-1, send(env->s_sock, buff, len, 0), "send");
	ringbuff_read(env->buf_write, buff, ret);
}
