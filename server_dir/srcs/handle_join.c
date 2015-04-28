/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 10:38:08 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 18:46:21 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

static char		*get_chan_name(char *input)
{
	input += ft_strlen("/join ");
	return (ft_strdup(input));
}

static char		*join_msg(char *joiner, char *chan)
{
	char	*ret;
	char	*tmp;

	ret = ft_strdup(joiner);
	tmp = ret;
	ret = ft_strjoin(tmp, " has joined ");
	free(tmp);
	tmp = ret;
	ret = ft_strjoin(tmp, chan);
	free(tmp);
	free(chan);
	return (ret);
}

char			*handle_join(t_env *env, int cs, char *input)
{
	t_channel	*tmp;
	char		*chan_name;

	tmp = env->chans;
	chan_name = get_chan_name(input);
	while (tmp)
	{
		if (tmp->name && ft_strequ(tmp->name, chan_name))
		{
			env->fds[cs].chan = tmp->id;
			free(input);
			return (join_msg(env->fds[cs].nick, chan_name));
		}
		else if (tmp->next == NULL)
		{
			env->fds[cs].chan = tmp->id + 1;
			tmp->next = create_channel(tmp->id + 1, chan_name);
			free(input);
			return (join_msg(env->fds[cs].nick, chan_name));
		}
		tmp = tmp->next;
	}
	free(input);
	return (NULL);
}
