/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_who.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 10:37:58 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 18:35:08 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

static char		*add_nick(char *buf_who, char *nick)
{
	char	*tmp;

	tmp = buf_who;
	buf_who = ft_strjoin(tmp, "\n");
	free(tmp);
	tmp = buf_who;
	buf_who = ft_strjoin(tmp, nick);
	free(tmp);
	return (buf_who);
}

char			*handle_who(t_env *env, int cs, char *input)
{
	int			i;
	char		*buf_who;
	char		*tmp;

	i = 0;
	buf_who = NULL;
	free(input);
	while (i < env->max_fd)
	{
		if (env->fds[i].chan != DEFAULT_CHAN
				&& env->fds[i].chan == env->fds[cs].chan)
			buf_who = add_nick(buf_who, env->fds[i].nick);
		++i;
	}
	tmp = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strjoin(tmp, buf_who);
	free(buf_who);
	return (NULL);
}
