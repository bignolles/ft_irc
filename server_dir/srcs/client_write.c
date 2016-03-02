/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 11:16:22 by marene            #+#    #+#             */
/*   Updated: 2016/03/02 16:03:38 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <libft.h>
#include <ft_error.h>
#include <server.h>

void	client_write(t_env *env, int cs)
{
	int		ret;
	int		len;
	char	*buff;
	char	*tmp;

	len = ft_strlen(env->fds[cs].buf_write) + 2;
	tmp = ft_strjoin(env->fds[cs].buf_write, "\n\r");
	ret = send(cs, tmp, len, 0);
	free(tmp);
	tryint(-1, ret, "send");
	buff = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strsub(buff, ret, len - ret);
	free(buff);
}
