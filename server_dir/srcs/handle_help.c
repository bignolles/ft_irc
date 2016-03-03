/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 18:38:50 by marene            #+#    #+#             */
/*   Updated: 2016/03/03 17:08:16 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <server.h>

extern t_cmd	g_cmd_table[CMD_NB];

char			*handle_help(t_env *env, int cs, char *input)
{
	int		i;

	i = 0;
	free(input);
	while (i < CMD_NB)
	{
		ringbuff_write(env->fds[cs].buf_write, "\n", 2);
		ringbuff_write(env->fds[cs].buf_write, g_cmd_table[i].cmd, ft_strlen(g_cmd_table[i].cmd));
		ringbuff_write(env->fds[cs].buf_write, g_cmd_table[i].desc, ft_strlen(g_cmd_table[i].desc));
		++i;
	}
	return (NULL);
}
