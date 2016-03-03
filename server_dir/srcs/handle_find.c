/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 16:58:42 by marene            #+#    #+#             */
/*   Updated: 2016/03/03 15:10:04 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

static void		insert(t_ringbuff *buff, char *to_insert)
{
	ringbuff_write(buff, "\n\r", 2);
	ringbuff_write(buff, to_insert, ft_strlen(to_insert));
}

char			*handle_find(t_env *env, int cs, char *input)
{
	char	**split;
	char	*ret;
	int		code;

	split = ft_ws_split(input);
	if (split[1] != NULL && split[2] == NULL)
	{
		if ((ret = get_chan_by_user(env, split[1], &code)) != NULL)
			insert(env->fds[cs].buf_write, ret);
		else if (code == USER_NO_EXIST)
			insert(env->fds[cs].buf_write, "No suche user");
		else if (code == USER_NOT_CONNECTED)
			insert(env->fds[cs].buf_write, "User is not connected to any channel");
	}
	else
		insert(env->fds[cs].buf_write, "Invalid arguments");
	return (NULL);
}
