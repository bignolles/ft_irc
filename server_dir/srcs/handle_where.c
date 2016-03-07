/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_where.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:06:20 by marene            #+#    #+#             */
/*   Updated: 2016/03/05 18:23:34 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <server.h>

char			*handle_where(t_env *env, int cs, char *input)
{
	char	*msg;

	if (ft_strlen(input) != ft_strlen("/where"))
		msg = ft_strdup("\nInvalid command");
	else
		msg = (env->fds[cs].chan == DEFAULT_CHAN) ?
				ft_strdup("\nYou are not connected to any channel") :
				ft_strjoin("\n", get_chan_by_id(env->chans, env->fds[cs].chan));
	ringbuff_write(env->fds[cs].buf_write, msg, ft_strlen(msg));
	ringbuff_write(env->fds[cs].buf_write, "\n\r", 2);
	free(msg);
	free(input);
	return (NULL);
}
