/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_add_in_pane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:24:46 by marene            #+#    #+#             */
/*   Updated: 2016/03/14 16:57:31 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	# include <stdio.h>

#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

t_pane		*libcurses_add_pane(t_screen *screen, char *pane_name, unsigned int flags, int *pos, int *dimension)
{
	t_pane			*new_pane;
	t_panelist		*it;

	new_pane = NULL;
	if ((flags & PANE_IO))
	{
		new_pane = libcurses_create_pane(pane_name, flags, pos, dimension);
		if (new_pane != NULL)
		{
			it = screen->panes;
			while (it->next != NULL)
				it = it->next;
			it->next = malloc(sizeof(t_panelist));
			if (it->next == NULL)
				libcurses_destruct_pane(&new_pane);
			else
			{
				it->next->pane = new_pane;
				it->next->next = NULL;
			}
		}
	}
	return (new_pane);
}
