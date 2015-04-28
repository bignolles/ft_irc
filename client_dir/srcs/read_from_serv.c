/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_serv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 19:21:42 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 18:37:49 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <client.h>

void	read_from_serv(t_env *env)
{
	char	buff[BUF_SIZE + 1];
	int		ret;

	ret = recv(env->s_sock, buff, BUF_SIZE, 0);
	if (ret <= 0)
	{
		ft_putendl("Disconnected from server");
		close(env->s_sock);
		free(env->buf_read);
		free(env->buf_write);
		init_env(env);
		wait_for_connect(env);
	}
	buff[ret] = '\0';
	ft_putendl(buff);
}
