/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_create_pane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:06:37 by marene            #+#    #+#             */
/*   Updated: 2016/05/06 14:30:30 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

static t_pane			*set_pane(int pane_id, char *pane_name, int *pos,
		int *dimension)
{
	t_window	*win;
	t_pane		*ret;

	ret = malloc(sizeof(t_pane));
	win = subwin(stdscr, (dimension[0] * LINES) / 100,
			(dimension[1] * COLS) / 100, (pos[0] * LINES) / 100,
			(pos[1] * COLS) / 100);
	if (ret && win)
	{
		ret->name = NULL;
		if (pane_name != NULL)
			ret->name = ft_strdup(pane_name);
		ret->id = pane_id;
		ret->pos[0] = (pos[0] * LINES) / 100;
		ret->pos[1] = (pos[1] * COLS) / 100;
		ret->dimension[0] = (dimension[0] * LINES) / 100;
		ret->dimension[1] = (dimension[1] * COLS) / 100;
		ret->win = win;
		ret->input_id = -1;
		ret->max_input_id = 0;
	}
	return (ret);
}

t_pane					*libcurses_create_pane(char *pane_name,
		unsigned int flags, int *pos, int *dimension)
{
	t_pane		*ret;
	static int	pane_id = 0;

	if ((ret = set_pane(pane_id, pane_name, pos, dimension)))
	{
		++pane_id;
		ret->flags = flags;
		if ((flags & PANE_BOXED))
		{
			box(ret->win, ACS_VLINE, ACS_HLINE);
			ret->padding[LEFT] = 1;
			ret->padding[RIGHT] = 1;
			ret->padding[TOP] = 1;
			ret->padding[BOTTOM] = 1;
		}
		else
		{
			ft_bzero(ret->padding, sizeof(int) * 4);
		}
		ft_bzero(ret->input_msg, LIBCURSES_MAX_INPUT + 1);
		ret->input_msg_len = 0;
		ret->cursor = 0;
		keypad(ret->win, TRUE);
	}
	return (ret);
}
