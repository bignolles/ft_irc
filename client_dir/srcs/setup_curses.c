/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_curses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:48:30 by marene            #+#    #+#             */
/*   Updated: 2016/03/16 13:08:27 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		setup_curses(t_env *env)
{
	int		dimension[2];
	int		pos[2];

	if (env->screen == NULL && (env->screen = libcurses_init()) != NULL)
	{
		libcurses_set_pos(dimension, 15, 80);
		libcurses_set_pos(pos, 0, 10);
		libcurses_add_pane(env->screen, BOX_CHAN_NAME, PANE_OUTPUT | PANE_BOXED, pos, dimension);
		libcurses_set_pos(dimension, 10, 100);
		libcurses_set_pos(pos, 90, 0);
		libcurses_add_pane(env->screen, BOX_INPUT, PANE_INPUT | PANE_BOXED, pos, dimension);
		libcurses_set_pos(dimension, 75, 100);
		libcurses_set_pos(pos, 15, 0);
		libcurses_add_pane(env->screen, BOX_CHAT, PANE_OUTPUT | PANE_BOXED, pos, dimension);
	}
}
