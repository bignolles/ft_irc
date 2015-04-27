/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_serv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 14:35:22 by marene            #+#    #+#             */
/*   Updated: 2015/04/22 19:09:42 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_error.h>
#include <client.h>

# include <stdio.h>

void	write_to_serv(t_env *env)
{
	int		ret;
	size_t	len;
	char	*buff;

	len = ft_strlen(env->buf_read);
	ret = tryint(-1, send(env->s_sock, env->buf_read, len, 0), "send");
	buff = env->buf_read;
	env->buf_read = ft_strsub(buff, ret, len - ret);
}
