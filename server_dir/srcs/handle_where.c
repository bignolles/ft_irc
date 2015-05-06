/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_where.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 17:06:20 by marene            #+#    #+#             */
/*   Updated: 2015/05/06 17:12:16 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <server.h>

char			*handle_where(t_env *env, int cs, char *input)
{
	char	*epur;
	char	*trim;
	char	*buf;
	char	*msg;

	trim = ft_strtrim(input);
	epur = ft_epurstr(trim);
	if (ft_strlen(epur) != ft_strlen("/where"))
		msg = ft_strdup("\nInvalid command");
	else
		msg = (env->fds[cs].chan == DEFAULT_CHAN) ?
				ft_strdup("\nYou are not connected to any channel") :
				ft_strjoin("\n", get_chan_by_id(env->chans, env->fds[cs].chan));
	buf = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strjoin(buf, msg);
	free(buf);
	free(msg);
	free(trim);
	free(epur);
	free(input);
	return (NULL);
}
