/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_curses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:48:30 by marene            #+#    #+#             */
/*   Updated: 2016/05/05 16:16:19 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"

void		setup_curses(t_env *env)
{
	int		dimension[2];
	int		pos[2];
	int		**dim_pos;

	dim_pos = malloc(sizeof(int*) * 2);
	if (env->screen == NULL && (env->screen = libcurses_init()) != NULL
			&& dim_pos != NULL)
	{
		dim_pos[0] = dimension;
		dim_pos[1] = pos;
		libcurses_set_pos(dimension, 15, 80);
		libcurses_set_pos(pos, 0, 10);
		libcurses_add_pane(env->screen, BOX_CHAN_NAME,
				PANE_OUTPUT | PANE_BOXED, dim_pos);
		libcurses_set_pos(dimension, 10, 100);
		libcurses_set_pos(pos, 90, 0);
		libcurses_add_pane(env->screen, BOX_INPUT,
				PANE_INPUT | PANE_BOXED, dim_pos);
		libcurses_set_pos(dimension, 75, 100);
		libcurses_set_pos(pos, 15, 0);
		libcurses_add_pane(env->screen, BOX_CHAT,
				PANE_OUTPUT | PANE_BOXED, dim_pos);
	}
}
