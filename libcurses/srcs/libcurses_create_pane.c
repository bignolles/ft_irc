/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_create_pane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:06:37 by marene            #+#    #+#             */
/*   Updated: 2016/03/14 15:11:24 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	# include <stdio.h>

#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

t_pane					*libcurses_create_pane(char *pane_name, unsigned int flags, int *pos, int *dimension)
{
	static int	pane_id = 0;
	WINDOW		*win;
	t_pane		*ret;

	win = subwin(stdscr, (dimension[0] * LINES) / 100, (dimension[1] * COLS) / 100, (pos[0] * LINES) / 100, (pos[1] * COLS) / 100);
	ret = malloc(sizeof(t_pane));
	if (ret != NULL && win != NULL)
	{
		ret->name = NULL;
		if (pane_name != NULL)
			ret->name = ft_strdup(pane_name);
		ret->id = pane_id;
		++pane_id;
		ret->pos[0] = (pos[0] * LINES) / 100;
		ret->pos[1] = (pos[1] * COLS) / 100;
		ret->dimension[0] = (dimension[0] * LINES) / 100;
		ret->dimension[1] = (dimension[1] * COLS) / 100;
		ret->win = win;
		ret->flags = flags;
		if ((flags & PANE_BOXED))
			box(ret->win, ACS_VLINE, ACS_HLINE);
	}
	return (ret);
}
