/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 11:16:22 by marene            #+#    #+#             */
/*   Updated: 2015/04/22 19:32:30 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <libft.h>
#include <ft_error.h>
#include <server.h>

# include <stdio.h>

void	client_write(t_env *env, int cs)
{
	int		ret;
	int		len;
	char	*buff;

	printf("\nCLIENT_WRITE\n");
	printf("\t[%d]buf->write = [%s]\n", cs, env->fds[cs].buf_write);
	len = ft_strlen(env->fds[cs].buf_write);
	ret = send(cs, env->fds[cs].buf_write, len, 0);
	printf("\tlen = %d, ret = %d\n", len, ret);
	tryint(-1, ret, "send");
	buff = env->fds[cs].buf_write;
	env->fds[cs].buf_write = ft_strsub(buff, ret, len - ret);
	printf("\t[%d]buf->write = [%s]\n", cs, env->fds[cs].buf_write);
	free(buff);
}
