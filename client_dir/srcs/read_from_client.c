/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 16:26:32 by marene            #+#    #+#             */
/*   Updated: 2016/04/25 17:43:58 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ft_error.h>
#include <client.h>

void			read_from_client(t_env *env)
{
	char	c;

	c = libcurses_input_char(env->screen, env->cursor);
	if (c != '\0')
	{
		if (c == '\n')
		{
			env->cursor = 0;
			libcurses_refresh_panes(env->screen);
			ringbuff_write(env->buf_write, &c, 1);
			ringbuff_write(env->buf_write, "\r", 1);
		}
		else if (c == 127)
		{
			if (env->cursor > 0)
				env->cursor -= 1;
			ringbuff_pop_last(env->buf_write);
			libcurses_refresh_panes(env->screen);
		}
		else
		{
			env->cursor += 1;
			ringbuff_write(env->buf_write, &c, 1);
		}
	}
}
