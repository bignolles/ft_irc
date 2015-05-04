/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 11:09:49 by marene            #+#    #+#             */
/*   Updated: 2015/05/04 16:55:29 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <server.h>
#include <libft.h>

void	disp_client_away(t_env *env, int cs)
{
	char	*buff;
	char	*cs_str;

	cs_str = ft_itoa(cs);
	buff = (env->fds[cs].nick == NULL) ? ft_strjoin("#", cs_str) :
		ft_strdup(env->fds[cs].nick);
	ft_putstr("client ");
	ft_putstr(buff);
	ft_putendl(" has gone away");
	free(cs_str);
	free(buff);
}

void	disp_new_client(int c_sock, struct sockaddr_in c_sin)
{
	char	*buff;

	ft_putstr("New client #");
	buff = ft_itoa(c_sock);
	ft_putstr(buff);
	free(buff);
	ft_putstr(" from ");
	buff = inet_ntoa(c_sin.sin_addr);
	ft_putstr(buff);
	buff = ft_itoa(ntohs(c_sin.sin_port));
	ft_putstr(":");
	ft_putendl(buff);
	free(buff);
}
