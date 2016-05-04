/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 16:26:32 by marene            #+#    #+#             */
/*   Updated: 2016/05/04 17:28:07 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ft_error.h>
#include <client.h>

void			read_from_client(t_env *env)
{
	char	*s;

	s = libcurses_input_char(env->screen);
	if (s != NULL)
	{
		ringbuff_write(env->buf_write, s, ft_strlen(s));
		free(s);
			ringbuff_write(env->buf_write, "\n\r", 2);
	}
	libcurses_refresh_panes(env->screen);
}
