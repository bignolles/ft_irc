/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_channels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 14:19:16 by marene            #+#    #+#             */
/*   Updated: 2016/03/08 17:04:19 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <colors.h>
#include <server.h>

static int			get_co_nb(t_env *env, int chan_id)
{
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	while (i < env->max_fd)
	{
		if (env->fds[i].chan == chan_id)
			++ret;
		++i;
	}
	return (ret);
}

static void			color_name(char **name)
{
	char	*tmp;

	tmp = *name;
	*name = ft_strjoin(GREEN, tmp);
	free(tmp);
	tmp = *name;
	*name = ft_strjoin(tmp, DEFAULT_COLOR);
	free(tmp);
}

static t_chan_list	*get_channels_recap(t_env *env, int cs, int *chan_nb)
{
	t_channel		*chan;
	t_chan_list		*ret;
	int				i;

	i = 0;
	chan = env->chans;
	*chan_nb = get_channels_nb(env->chans);
	ret = tryptr(NULL, malloc(sizeof(t_chan_list) * *chan_nb), "malloc");
	while (i < *chan_nb)
	{
		if (chan->id != DEFAULT_CHAN)
		{
			ret[i].name = ft_strdup(chan->name);
			ret[i].co_nb = get_co_nb(env, chan->id);
			if (env->fds[cs].chan == chan->id)
				color_name(&ret[i].name);
			++i;
		}
		chan = chan->next;
	}
	return (ret);
}

static void			insert_msg(t_env *env, int cs, t_chan_list chan)
{
	char	*tmp;

	tmp = ft_itoa(chan.co_nb);
	ringbuff_write(env->fds[cs].buf_write, "\n", 2);
	ringbuff_write(env->fds[cs].buf_write, chan.name, ft_strlen(chan.name));
	ringbuff_write(env->fds[cs].buf_write, "[", 1);
	ringbuff_write(env->fds[cs].buf_write, tmp, ft_strlen(tmp));
	ringbuff_write(env->fds[cs].buf_write, "]", 1);
	free(tmp);
}

char				*handle_channels(t_env *env, int cs, char *input)
{
	t_chan_list		*chans;
	int				chans_nb;
	int				i;

	free(input);
	i = 0;
	chans = get_channels_recap(env, cs, &chans_nb);
	if (chans_nb == 0)
	{
		ringbuff_write(env->fds[cs].buf_write, "No channels (yet)",
				RINGBUFF_CHUNK_SIZE);
	}
	while (i < chans_nb)
	{
		insert_msg(env, cs, chans[i]);
		free(chans[i].name);
		++i;
	}
	ringbuff_write(env->fds[cs].buf_write, "\n\r", 2);
	free(chans);
	return (NULL);
}
