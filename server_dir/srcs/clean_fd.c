/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/29 12:38:55 by marene            #+#    #+#             */
/*   Updated: 2014/10/31 15:58:52 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <server.h>

void	clean_fd(t_fd *fd)
{
	fd->type = FD_FREE;
	fd->fct_read = NULL;
	fd->fct_write = NULL;
	fd->buf_write = NULL;
	fd->nick = NULL;
}
