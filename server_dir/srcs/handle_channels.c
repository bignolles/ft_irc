/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_channels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 14:19:16 by marene            #+#    #+#             */
/*   Updated: 2015/05/04 09:54:27 by marene           ###   ########.fr       */
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
	char	*tmp2;

	tmp2 = ft_itoa(chan.co_nb);
	tmp = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strjoin(tmp, chan.name);
	free(tmp);
	tmp = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strjoin(tmp, " [");
	free(tmp);
	tmp = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	tmp = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strjoin(tmp, "]\n");
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
	while (i < chans_nb)
	{
		insert_msg(env, cs, chans[i]);
		free(chans[i].name);
		++i;
	}
	free(chans);
	return (NULL);
}
