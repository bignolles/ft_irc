/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 16:26:32 by marene            #+#    #+#             */
/*   Updated: 2016/02/29 19:26:36 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ft_error.h>
#include <client.h>

static int	is_exit(char *input)
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

void		read_from_client(t_env *env)
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
//		ft_putstr("env->buf_write read space : ");
//		ft_putnbr(ringbuff_get_read_space(env->buf_write));
//		ft_putchar('\n');
//		ft_putendl(env->buf_write->buff);
	}
}
