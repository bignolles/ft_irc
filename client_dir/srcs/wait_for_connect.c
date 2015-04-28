/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_connection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 14:01:18 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 14:29:59 by marene           ###   ########.fr       */
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
	char	r_buf[BUF_SIZE + 1];
	char	*trimmed;
	char	**args;
	int		ret;

	while ((ret = read(1, r_buf, BUF_SIZE)) != -1)
	{
		args = NULL;
		r_buf[ret] = '\0';
		trimmed = ft_strtrim(r_buf);
		if (ft_strstr(trimmed, CONNECT_CMD) == trimmed)
		{
			args = ft_strsplit(trimmed, ' ');
			if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
			{
				usage("./client");
				exit(EXIT_FAILURE);
			}
			get_opt(env, args[1], args[2]);
			create_client(env);
			run_client(env);
		}
		free(trimmed);
		free_args(args);
	}
}
