/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_destruct_screen.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:52:05 by marene            #+#    #+#             */
/*   Updated: 2016/03/16 13:00:27 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libcurses.h"

static void		destruct_input(t_input *in)
{
	t_input		*tmp;

	while (in != NULL)
	{
		free(in->msg);
		tmp = in;
		in = in->next;
		free(tmp);
	}
}

static void		destruct_pane(t_pane *pane)
{
	free(pane->name);
	free(pane->win);
	destruct_input(pane->inputs);
}

void			libcurses_destruct_screen(t_screen **screen)
{
	t_panelist		*it;
	t_panelist		*tmp;

	it = (*screen)->panes;
	tmp = NULL;
	while (it != NULL)
	{
		if (it->pane)
			destruct_pane(it->pane);
		tmp = it;
		it = it->next;
		free(tmp);
	}
	free(*screen);
	*screen = NULL;
}
