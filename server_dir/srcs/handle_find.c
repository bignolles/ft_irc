/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 16:58:42 by marene            #+#    #+#             */
/*   Updated: 2015/05/06 17:46:28 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

static char		*insert(char *buf, char *to_insert)
{
	char	*tmp;

	tmp = buf;
	buf = ft_strjoin(tmp, "\n");
	free(tmp);
	tmp = buf;
	buf = ft_strjoin(tmp, to_insert);
	free(tmp);
	return (buf);
}

char			*handle_find(t_env *env, int cs, char *input)
{
	char	**split;
	char	*ret;
	int		code;

	split = ft_strsplit(input, ' ');
	if (split[1] != NULL && split[2] == NULL)
	{
		if ((ret = get_chan_by_user(env, split[1], &code)) != NULL)
			env->fds[cs].buf_write = insert(env->fds[cs].buf_write, ret);
		else if (code == USER_NO_EXIST)
			env->fds[cs].buf_write = insert(env->fds[cs].buf_write,
					"No suche user");
		else if (code == USER_NOT_CONNECTED)
			env->fds[cs].buf_write = insert(env->fds[cs].buf_write,
					"User is not connected to any channel");
	}
	else
		env->fds[cs].buf_write = insert(env->fds[cs].buf_write,
				"Invalid arguments");
	return (NULL);
}
