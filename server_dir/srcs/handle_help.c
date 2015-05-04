/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 18:38:50 by marene            #+#    #+#             */
/*   Updated: 2015/05/04 16:45:42 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <server.h>

extern t_cmd	g_cmd_table[CMD_NB];

char			*handle_help(t_env *env, int cs, char *input)
{
	int		i;
	char	*tmp;

	i = 0;
	free(input);
	while (i < CMD_NB)
	{
		tmp = env->fds[cs].buf_write;
		env->fds[cs].buf_write = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp = env->fds[cs].buf_write;
		env->fds[cs].buf_write = ft_strjoin(tmp, g_cmd_table[i].cmd);
		free(tmp);
		tmp = env->fds[cs].buf_write;
		env->fds[cs].buf_write = ft_strjoin(tmp, ": ");
		free(tmp);
		tmp = env->fds[cs].buf_write;
		env->fds[cs].buf_write = ft_strjoin(tmp, g_cmd_table[i].desc);
		free(tmp);
		++i;
	}
	return (NULL);
}
