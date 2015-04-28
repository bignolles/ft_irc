/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 11:16:22 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 18:23:27 by marene           ###   ########.fr       */
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

	len = ft_strlen(env->fds[cs].buf_write);
	ret = send(cs, env->fds[cs].buf_write, len, 0);
	tryint(-1, ret, "send");
	buff = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strsub(buff, ret, len - ret);
	free(buff);
}
