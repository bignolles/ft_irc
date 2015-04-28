/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 12:07:06 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 13:15:43 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <server.h>

static void		free_args(char **args)
{
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		++i;
	}
	free(args);
}

static void		send_a_message(t_env *env, int c_nb, char *sender, char *msg)
{
	char	*tmp;

	tmp = env->fds[c_nb].buf_write;
	env->fds[c_nb].buf_write = ft_strjoin(tmp, "\n");
	free(tmp);
	tmp = env->fds[c_nb].buf_write;
	env->fds[c_nb].buf_write = ft_strjoin(tmp, sender);
	free(tmp);
	tmp = env->fds[c_nb].buf_write;
	env->fds[c_nb].buf_write = ft_strjoin(tmp, ": ");
	free(tmp);
	tmp = env->fds[c_nb].buf_write;
	env->fds[c_nb].buf_write = ft_strjoin(tmp, msg);
	free(tmp);
}

char			*handle_msg(t_env *env, int cs, char *input)
{
	char	**args;
	char	*tmp;
	int		i;

	args = ft_strsplit(input, ' ');
	if (args[1] != NULL && args[2] != NULL)
	{
		i = 0;
		while (i < env->max_fd)
		{
			if (env->fds[i].nick != NULL
					&& ft_strequ(args[1], env->fds[i].nick))
			{
				send_a_message(env, i, env->fds[cs].nick, args[2]);
				free_args(args);
				return (NULL);
			}
			++i;
		}
		tmp = env->fds[cs].buf_write;
		env->fds[cs].buf_write = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp = env->fds[cs].buf_write;
		env->fds[cs].buf_write = ft_strjoin(tmp, args[1]);
		free(tmp);
		tmp = env->fds[cs].buf_write;
		env->fds[cs].buf_write = ft_strjoin(tmp, " does not exist, or is not connected");
		free(tmp);
		ft_putendl(env->fds[cs].buf_write);
	}
	free_args(args);
	return (NULL);
}
