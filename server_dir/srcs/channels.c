/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 18:21:45 by marene            #+#    #+#             */
/*   Updated: 2015/05/06 11:01:27 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

t_channel	*create_channel(int id, char *name)
{
	t_channel	*ret;

	if ((ret = (t_channel *)malloc(sizeof(t_channel))) != NULL)
	{
		ret->id = id;
		ret->name = ft_strdup(name);
		ret->next = NULL;
	}
	return (ret);
}

int			add_channel(t_env *env, t_channel *new)
{
	t_channel	*tmp;

	tmp = env->chans;
	while (tmp)
	{
		if (tmp->id == new->id ||
		(tmp->name && ft_strcmp(tmp->name, new->name)) == 0)
			return (SERV_ERROR);
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return (SERV_OK);
		}
		tmp = tmp->next;
	}
	return (SERV_ERROR);
}

char		*get_chan_by_id(t_channel *chan, int id)
{
	int		i;

	i = 0;
	if (id != DEFAULT_CHAN)
	{
		while (chan)
		{
			if (chan->id == id)
				return (chan->name);
			chan = chan->next;
		}
	}
	return (NULL);
}

char		*get_chan_by_user(t_env *env, char *user_name, int *code)
{
	int			i;

	i = 0;
	while (i < env->max_fd)
	{
		if (env->fds[i].nick && ft_strequ(env->fds[i].nick, user_name))
		{
			*code = USER_NOT_CONNECTED;
			return (get_chan_by_id(env->chans, env->fds[i].chan));
		}
		++i;
	}
	*code = USER_NO_EXIST;
	return (NULL);
}

int			get_channels_nb(t_channel *chan)
{
	int		ret;

	ret = 0;
	while (chan)
	{
		if (chan->id != DEFAULT_CHAN)
			++ret;
		chan = chan->next;
	}
	return (ret);
}
