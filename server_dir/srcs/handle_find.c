/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 16:58:42 by marene            #+#    #+#             */
/*   Updated: 2015/05/04 17:13:51 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

char			*handle_find(t_env *env, int cs, char *input)
{
	char	**split;
	char	*tmp;
	char	*ret;
	int		code;

	split = ft_strsplit(input, ' ');
	if (split[1] != NULL && split[2] == NULL)
	{
		if ((ret = get_chan_by_user(env, split[1]), &code) != NULL)
		{
			tmp = env->fds[cs].buf_write;
			env->fds[cs].buf_write = ft_strjoin(tmp, "\n");
			free(tmp);
			tmp = env->fds[cs].buf_write;
			env->fds[cs].buf_write = ft_strjoin(tmp, ret);
			free(tmp);
		}
		else if (code == USER_NO_EXIST)
		{
			tmp = env->fds[cs].buf_write;
			env->fds[cs].buf_write = ft_strjoin(tmp, "\nNo such user");
			free(tmp);
		}
		else if (code == USER_NO_CONNECTED)
		{
			tmp = env->fds[cs].buf_write;
			env->fds[cs].buf_write = ft_strjoin(tmp,
					"\nUser is nto connected to any channel");
			free(tmp);
		}
	}
	else
	{
		tmp = env->fds[cs].buf_write;
		env->fds[cs].buf_write = ft_strjoin(tmp, "\nInvalid arguments");
		free(tmp);
	}
	return (NULL);
}
