/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 12:07:06 by marene            #+#    #+#             */
/*   Updated: 2015/05/04 10:01:09 by marene           ###   ########.fr       */
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

static void		send_a_message(t_env *env, int c_nb, char *msg)
{
	char	*tmp;

	tmp = env->fds[c_nb].buf_write;
	env->fds[c_nb].buf_write = ft_strjoin(tmp, msg);
	free(tmp);
	tmp = env->fds[c_nb].buf_write;
	env->fds[c_nb].buf_write = ft_strjoin(tmp, " ");
	free(tmp);
}

static void		unresolved_dest(t_env *env, char *dest, int cs)
{
	char	*tmp;

	tmp = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strjoin(tmp, "\n");
	free(tmp);
	tmp = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strjoin(tmp, dest);
	free(tmp);
	tmp = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strjoin(tmp,
			" does not exist, or is not connected");
	free(tmp);
}

static char		*add_sender(char *buf, char *sender)
{
	char	*tmp;

	tmp = buf;
	buf = ft_strjoin(tmp, "\n");
	free(tmp);
	tmp = buf;
	buf = ft_strjoin(tmp, PRIVATE_OPEN);
	free(tmp);
	tmp = buf;
	buf = ft_strjoin(tmp, sender);
	free(tmp);
	tmp = buf;
	buf = ft_strjoin(tmp, PRIVATE_CLOSE);
	free(tmp);
	return (buf);
}

char			*handle_msg(t_env *env, int cs, char *input)
{
	char	**args;
	int		i;
	int		j;

	args = ft_strsplit(input, ' ');
	if (args[1] != NULL && args[2] != NULL)
	{
		i = -1;
		while (++i < env->max_fd)
		{
			if (env->fds[i].nick && ft_strequ(args[1], env->fds[i].nick))
			{
				j = 1;
				env->fds[i].buf_write = add_sender(env->fds[i].buf_write,
						env->fds[cs].nick);
				while (args[++j])
					send_a_message(env, i, args[j]);
				free_args(args);
				return (NULL);
			}
		}
		unresolved_dest(env, args[1], cs);
	}
	free_args(args);
	return (NULL);
}
