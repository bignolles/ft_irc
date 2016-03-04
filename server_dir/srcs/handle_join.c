/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 10:38:08 by marene            #+#    #+#             */
/*   Updated: 2016/03/04 11:24:25 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

static char		*get_chan_name(t_env *env, int cs, char *input)
{
	char		*ret;
	size_t		join_len;

	join_len = ft_strlen("/join ");
	if (ft_strlen(input) <= join_len)
	{
		free(input);
		ringbuff_write(env->fds[cs].buf_write, "Invalid chan name", RINGBUFF_CHUNK_SIZE);
		return (NULL);
	}
	ret = ft_strdup(input + join_len);
	free(input);
	return (ret);
}

static char		*leave_msg(t_channel *chan, int id, char *nick)
{
	char	*old_chan_name;
	char	*msg;
	char	*tmp;

	old_chan_name = get_chan_by_id(chan, id);
	msg = ft_strdup(nick);
	tmp = msg;
	msg = ft_strjoin(tmp, " has left ");
	free(tmp);
	tmp = msg;
	msg = ft_strjoin(tmp, old_chan_name);
	free(tmp);
	return (msg);
}

static void		leave_chan(t_env *env, int cs, int new_chan)
{
	char	*msg;
	int		i;

	if (env->fds[cs].chan != DEFAULT_CHAN)
	{
		i = 0;
		msg = leave_msg(env->chans, env->fds[cs].chan, env->fds[cs].nick);
		while (i < env->max_fd)
		{
			if (i != cs && env->fds[i].chan == env->fds[cs].chan)
				ringbuff_write(env->fds[i].buf_write, msg, ft_strlen(msg)); //  quelque part nan?
			++i;
		}
		free(msg);
	}
	env->fds[cs].chan = new_chan;
}

static char		*join_msg(t_env *env, int cs, int new_chan, char *chan)
{
	char	*ret;
	char	*tmp;

	ringbuff_write(env->fds[cs].buf_write, "You joined ", RINGBUFF_CHUNK_SIZE);
	ringbuff_write(env->fds[cs].buf_write, chan, ft_strlen(chan));
	ret = ft_strdup(env->fds[cs].nick);
	tmp = ret;
	ret = ft_strjoin(tmp, " has joined ");
	free(tmp);
	tmp = ret;
	ret = ft_strjoin(tmp, chan);
	free(tmp);
	leave_chan(env, cs, new_chan);
	return (ret);
}

char			*handle_join(t_env *env, int cs, char *input)
{
	t_channel	*tmp;
	char		*chan_name;
	char		*ret;

	ft_putendl("handle_join");
	tmp = env->chans;
	if ((chan_name = get_chan_name(env, cs, input)) == NULL)
		return (NULL);
	while (tmp)
	{
		if (tmp->name && ft_strequ(tmp->name, chan_name))
		{
			ret = join_msg(env, cs, tmp->id, chan_name);
			return (ret);
		}
		else if (tmp->next == NULL)
		{
			tmp->next = create_channel(tmp->id + 1, chan_name);
			return (join_msg(env, cs, tmp->id + 1, chan_name));
		}
		tmp = tmp->next;
	}
	return (NULL);
}
