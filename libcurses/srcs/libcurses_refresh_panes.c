/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_refresh_panes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:08:30 by marene            #+#    #+#             */
/*   Updated: 2016/03/14 16:58:00 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libcurses.h"

void		libcurses_refresh_panes(t_screen *screen)
{
	t_panelist	*it;

	it = screen->panes;
	while (it != NULL)
	{
		if (it->pane)
			wrefresh(it->pane->win);
		it = it->next;
	}
}
