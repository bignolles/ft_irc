/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 16:26:32 by marene            #+#    #+#             */
/*   Updated: 2016/03/04 17:02:21 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

#include <unistd.h>
#include <libft.h>
#include <ft_error.h>
#include <client.h>

static int		is_exit(char *input)
{
	char	*trim;

	trim = ft_strtrim(input);
	if (ft_strequ(trim, "/exit"))
	{
		free(trim);
		return (1);
	}
	else
	{
		free(trim);
		return (0);
	}
}

void			read_from_client(t_env *env)
{
	char	buffer[RINGBUFF_CHUNK_SIZE + 1];
	int		ret;

	ret = tryint(-1, read(1, buffer, RINGBUFF_CHUNK_SIZE), "read");
	if (ret > 0)
	{
		buffer[ret] = '\0';
		if (is_exit(buffer))
		{
			close(env->s_sock);
			exit(0);
		}
		ringbuff_write(env->buf_write, buffer, ret);
		if (ft_strchr(buffer, '\n') == buffer + ft_strlen(buffer) - 1)
			ringbuff_write(env->buf_write, "\r", 2);
	}
}
