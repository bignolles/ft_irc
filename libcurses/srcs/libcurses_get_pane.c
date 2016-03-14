/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_get_pane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:44:59 by marene            #+#    #+#             */
/*   Updated: 2016/03/14 16:56:53 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libcurses.h"

t_pane		*libcurses_get_pane_by_name(t_screen *screen, char *name)
{
	t_panelist	*it;

	it = screen->panes;
	while (it != NULL)
	{
		if (it->pane && ft_strequ(it->pane->name, name))
			return (it->pane);
		it = it->next;
	}
	return (NULL);
}

t_pane		*libcurses_get_pane_by_id(t_screen *screen, int id)
{
	t_panelist	*it;

	it = screen->panes;
	while (it != NULL)
	{
		if (it->pane && it->pane->id == id)
			return (it->pane);
		it = it->next;
	}
	return (NULL);
}
