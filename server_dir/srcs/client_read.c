/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 17:12:58 by marene            #+#    #+#             */
/*   Updated: 2016/03/07 19:00:58 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_error.h>
#include <server.h>

/*
 * TODO : function commented for the time being, remove it if further test prove that it was indeed useless
static void		zero_buff(char *buff, int start)
{
	int		i;

	i = start;
	while (i < RINGBUFF_CHUNK_SIZE)
	{
		buff[i] = '\0';
		++i;
	}
}
*/

void			client_read(t_env *env, int cs)
{
	int		ret;
	int		i;
	char	*cmd_ret;
	char	*to_read;
	char	buff[RINGBUFF_CHUNK_SIZE + 1];

	ft_putendl("client_read");
	buff[RINGBUFF_CHUNK_SIZE] = '\0';
	ret = recv(cs, buff, RINGBUFF_CHUNK_SIZE, 0);
	buff[ret] = '\0';
	ft_putstr("\t-> ");
	ft_putendl(buff);
	if (ret <= 0)
		end_connection(env, cs);
	else
	{
		i = 0;
//		zero_buff(buff, ret); // Pas sur que ce soit utile a present
		ringbuff_write(env->fds[cs].buf_read, buff, ret);
		ret = ringbuff_read_to_str(env->fds[cs].buf_read, &to_read, "\n\r");
		if (ret > 0)
		{
			to_read[ret - 1] = '\0'; // |
			to_read[ret - 2] = '\0'; // |-> Just getting the ending "\n\r" out of the way, i'll find a cleaner way to do so later
			cmd_ret = get_client_input(env, cs, to_read);
	//		ringbuff_write(env->fds[cs].buf_write, "\n\r", 2); 
			while (i < env->max_fd && env->fds[cs].chan != 0
					&& cmd_ret != NULL && ft_strlen(cmd_ret) > 0)
			{
				if (env->fds[i].type == FD_CLIENT && i != cs &&
						env->fds[i].chan == env->fds[cs].chan)
				{
					ringbuff_write(env->fds[i].buf_write, cmd_ret, ft_strlen(cmd_ret));
					ringbuff_write(env->fds[i].buf_write, "\n\r", 2);
				}
				++i;
			}
			free(cmd_ret);
		}
	}
}
