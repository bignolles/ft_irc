/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/01 16:11:56 by marene            #+#    #+#             */
/*   Updated: 2014/11/02 16:26:56 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/resource.h>
#include <client.h>
#include <ft_error.h>

void	init_env(t_env *env)
{
	env->buf_read = NULL;
	env->buf_write = NULL;
}
