/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:50:26 by marene            #+#    #+#             */
/*   Updated: 2016/02/29 16:25:10 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "client.h"

void		env_delete(t_env *env)
{
	close(env->s_sock);
	ringbuff_destruct(&(env->buf_write));
	ringbuff_destruct(&(env->buf_read));
}
