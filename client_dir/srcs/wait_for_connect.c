/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_connection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 14:01:18 by marene            #+#    #+#             */
/*   Updated: 2016/04/01 16:42:21 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <client.h>

static void		free_args(char **args)
{
	int		i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			++i;
		}
		free(args);
	}
}

void			wait_for_connect(t_env *env)
{
	char		*buff;
	char		*trim;
	char		**args;
	int			len;

	read_from_client(env);
	libcurses_refresh_panes(env->screen);
	buff = NULL;
	len = ringbuff_read_to_str(env->buf_write, &buff, "\n\r");
	if (buff != NULL && ft_strlen(buff) > 0)
	{
		trim = ft_strtrim(buff);
		if (ft_strstr(trim, CONNECT_CMD) == trim)
		{
			args = ft_strsplit(trim, ' ');
			if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
			{
				ringbuff_write(env->buf_read, "Invalid Command.", RINGBUFF_CHUNK_SIZE);
				free_args(args);
			}
			else
			{
				get_opt(env, args[1], args[2]);
				free_args(args);
				connect_client(env);
				run_client(env);
			}
		}
		else if (ft_strequ(trim, EXIT_CMD))
		{
			env_delete(env);
			libcurses_reinit();
			exit(0);
		}
	}
}
