/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 12:07:06 by marene            #+#    #+#             */
/*   Updated: 2016/03/04 17:36:10 by marene           ###   ########.fr       */
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
	ringbuff_write(env->fds[c_nb].buf_write, msg, ft_strlen(msg));
	ringbuff_write(env->fds[c_nb].buf_write, " ", 1);
}

static void		unresolved_dest(t_env *env, char *dest, int cs)
{
	ringbuff_write(env->fds[cs].buf_write, dest, ft_strlen(dest));
	ringbuff_write(env->fds[cs].buf_write, " does not exist, or is not connected", RINGBUFF_CHUNK_SIZE);// Peut etre \n\r nan?
}

static void		add_sender(t_ringbuff *buff, char *sender)
{

	ringbuff_write(buff, PRIVATE_OPEN, ft_strlen(PRIVATE_OPEN));
	ringbuff_write(buff, sender, ft_strlen(sender));
	ringbuff_write(buff, PRIVATE_CLOSE, ft_strlen(PRIVATE_CLOSE));
}

char			*handle_msg(t_env *env, int cs, char *input)
{
	char	**args;
	int		i;
	int		j;

	args = ft_ws_split(input);
	if (args[1] != NULL && args[2] != NULL)
	{
		i = -1;
		while (++i < env->max_fd)
		{
			if (env->fds[i].nick && ft_strequ(args[1], env->fds[i].nick))
			{
				j = 1;
				add_sender(env->fds[i].buf_write, env->fds[cs].nick);
				while (args[++j])
					send_a_message(env, i, args[j]);
				ringbuff_write(env->fds[i].buf_write, "\n\r", 2);
				free_args(args);
				return (NULL);
			}
		}
		unresolved_dest(env, args[1], cs);
	}
	free_args(args);
	return (NULL);
}
