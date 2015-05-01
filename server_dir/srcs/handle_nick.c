/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 16:51:56 by marene            #+#    #+#             */
/*   Updated: 2015/05/01 11:24:28 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <server.h>

static int		is_empty(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_iswhite(s[i]))
			return (0);
		++i;
	}
	return (1);
}

static char		*nick_msg(t_env *env, int cs, char *new_nick)
{
	char	*ret;
	char	*buff;

	ret = (env->fds[cs].nick == NULL) ? ft_itoa(cs) :
		ft_strdup(env->fds[cs].nick);
	buff = ft_strjoin(ret, " is now know as ");
	free(env->fds[cs].nick);
	env->fds[cs].nick = ft_strdup(new_nick);
	free(ret);
	ret = ft_strjoin(buff, new_nick);
	free(buff);
	free(new_nick);
	return (ret);
}

char			*handle_nick(t_env *env, int cs, char *input)
{
	char	*buff;
	char	*nick;
	int		nick_len;

	nick_len = ft_strlen("/NICK ");
	nick = ft_strsub(input, nick_len, ft_strlen(input) - nick_len - 1);
	free(input);
	if (!is_empty(nick))
		return (nick_msg(env, cs, nick));
	else
	{
		buff = env->fds[cs].buf_write;
		env->fds[cs].buf_write = ft_strjoin(buff, "\ninvalid nickname");
		return (NULL);
	}
}
