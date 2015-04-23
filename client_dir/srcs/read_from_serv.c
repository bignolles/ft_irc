/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_serv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 19:21:42 by marene            #+#    #+#             */
/*   Updated: 2014/11/02 18:57:22 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <client.h>

void	read_from_serv(t_env *env)
{
	char	buff[BUF_SIZE + 1];
	int		ret;

	ret = tryint(-1, recv(env->s_sock, buff, BUF_SIZE, 0), "connection ended");
	buff[ret] = '\0';
	ft_putendl(buff);
}
