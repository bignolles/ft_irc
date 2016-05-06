/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_connection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 14:01:18 by marene            #+#    #+#             */
/*   Updated: 2016/05/05 14:58:40 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <client.h>

void			free_args(char **args)
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
	}
}

static void		parse_user_input(t_env *env, char *input)
{
	char		**args;

	if (ft_strstr(input, CONNECT_CMD) == input)
	{
		args = ft_strsplit(input, ' ');
		if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
		{
			ringbuff_write(env->buf_read, "Invalid Command.\n\r",
					RINGBUFF_CHUNK_SIZE);
			free_args(args);
		}
		else
		{
			get_opt(env, args);
			connect_client(env);
			run_client(env);
		}
	}
	else if (ft_strequ(input, EXIT_CMD))
		do_exit(env);
	else
		ringbuff_write(env->buf_read, "Invalid Command.\n\r",
				RINGBUFF_CHUNK_SIZE);
}

void			wait_for_connect(t_env *env)
{
	char		*buff;
	char		*trim;
	int			len;

	read_from_client(env);
	libcurses_refresh_panes(env->screen);
	buff = NULL;
	len = ringbuff_read_to_str(env->buf_write, &buff, "\n\r");
	endwin();
	ft_putendl(buff);
	if (buff != NULL && ft_strlen(buff) > 0)
	{
		trim = ft_strtrim(buff);
		if (trim != NULL)
			parse_user_input(env, trim);
	}
}
