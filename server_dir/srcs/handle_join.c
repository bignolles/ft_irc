/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 10:38:08 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 11:31:24 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

# include <stdio.h>

char		*get_chan_name(char *input)
{
	input += ft_strlen("/join ");
	return (ft_strdup(input));
}

char		*handle_join(t_env *env, int cs, char *input)
{
	t_channel	*tmp;
	char		*chan_name;
	char		*buf;
	char		*ret;

	printf("HANDLE_JOIN\n");
	tmp = env->chans;
	chan_name = get_chan_name(input);
	while (tmp)
	{
		printf("tmp->name = %s\n", (tmp->name == NULL) ? "0x0" : tmp->name);
		printf("chan_name = %s\n", (chan_name == NULL) ? "0x0" : chan_name);
		if (tmp->name && ft_strequ(tmp->name, chan_name))
		{
			env->fds[cs].chan = tmp->id;
			ret = ft_strjoin(env->fds[cs].nick, " has joined ");
			buf = ret;
			ret = ft_strjoin(buf, tmp->name);
			printf("\t%s joins [%s]\n", env->fds[cs].nick, chan_name);
			free(buf);
			free(chan_name);
			return (ret);
		}
		else if (tmp->next == NULL)
		{
			printf("coucou\n");
			env->fds[cs].chan = tmp->id + 1;
			tmp->next = create_channel(tmp->id + 1, chan_name);
			printf("coucou\n");
			ret = ft_strjoin(env->fds[cs].nick, " has joined ");
			printf("coucou\n");
			buf = ret;
			ret = ft_strjoin(buf, tmp->name);
			printf("\t%s creates [%s]\n", env->fds[cs].nick, chan_name);
			free(buf);
			free(chan_name);
			return (ret);
		}
		printf("toto\n");
		tmp = tmp->next;
	}
	printf("return null\n");
	return (NULL);
}
