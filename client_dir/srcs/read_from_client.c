/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_client.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/02 16:26:32 by marene            #+#    #+#             */
/*   Updated: 2015/04/22 19:10:30 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <ft_error.h>
#include <client.h>

# include <stdio.h>

void	read_from_client(t_env *env)
{
	char	*tmp;
	char	buffer[BUF_SIZE + 1];
	int		ret;

	ret = tryint(-1, read(1, buffer, BUF_SIZE), "read");
	if (ret > 0 && buffer[0] != '\n')
	{
		buffer[ret] = '\0';
		tmp = env->buf_read;
		env->buf_read = ft_strjoin(tmp, buffer);
		free(tmp);
	}
}
