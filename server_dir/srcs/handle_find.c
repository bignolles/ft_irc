/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 16:58:42 by marene            #+#    #+#             */
/*   Updated: 2016/03/05 17:59:18 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

char			*handle_find(t_env *env, int cs, char *input)
{
	char	**split;
	char	*ret;
	int		code;

	split = ft_ws_split(input);
	if (split[1] != NULL && split[2] == NULL)
	{
		if ((ret = get_chan_by_user(env, split[1], &code)) != NULL)
			ringbuff_write(env->fds[cs].buf_write, ret, RINGBUFF_CHUNK_SIZE);
		else if (code == USER_NO_EXIST)
			ringbuff_write(env->fds[cs].buf_write, "No such user", RINGBUFF_CHUNK_SIZE);
		else if (code == USER_NOT_CONNECTED)
			ringbuff_write(env->fds[cs].buf_write, "User is not connected to any channel", RINGBUFF_CHUNK_SIZE);
	}
	else
		ringbuff_write(env->fds[cs].buf_write, "Invalid arguments", RINGBUFF_CHUNK_SIZE);
	ringbuff_write(env->fds[cs].buf_write, "\n\r", 2);
	return (NULL);
}
