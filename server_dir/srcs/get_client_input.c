/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_client_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 16:04:38 by marene            #+#    #+#             */
/*   Updated: 2015/05/04 10:00:42 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <server.h>

extern t_cmd	g_cmd_table[CMD_NB];

static char		*handle_cmd(t_env *env, int cs, char *input)
{
	int		i;

	i = 0;
	while (i < CMD_NB)
	{
		if (ft_strstr(input, g_cmd_table[i].cmd) == input)
			return (g_cmd_table[i].handler(env, cs, input));
		++i;
	}
	return (ft_strdup(CMD_ERROR));
}

char			*get_client_input(t_env *env, int cs, char *input)
{
	char	*epur;
	char	*buff;
	char	*ret;

	epur = ft_epurstr(input);
	if (epur[0] == CMD_CHAR)
		return (handle_cmd(env, cs, epur));
	else
	{
		ret = ft_strjoin(PUBLIC_OPEN, env->fds[cs].nick);
		buff = ret;
		ret = ft_strjoin(buff, PUBLIC_CLOSE);
		free(buff);
		buff = ret;
		ret = ft_strjoin(buff, epur);
		free(buff);
		free(epur);
		return (ret);
	}
}
