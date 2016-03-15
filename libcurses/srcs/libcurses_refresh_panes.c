/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_refresh_panes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:08:30 by marene            #+#    #+#             */
/*   Updated: 2016/03/15 17:23:27 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libcurses.h"

static int	get_lines_nb(char *str, int cols)
{
	int		lines_nb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lines_nb = 1;
	while (str[i])
	{
		++j;
		if (j >= cols || str[i] == '\n')
		{
			j = 0;
			++lines_nb;
		}
		++i;
	}
	return (lines_nb);
}

void		libcurses_print(t_pane *pane)
{
	int			cursor[2];
	t_input		*it;
	int			i;
	int			j;

	cursor[0] = pane->dimension[0];
	it = pane->inputs;
	while (it != NULL)
	{
		i = 0;
		j = 0;
		cursor[0] -= (get_lines_nb(it->msg, pane->dimension[1] - pane->padding[RIGHT] - pane->padding[LEFT]) + 1);
		cursor[1] = pane->padding[LEFT];
		while (it->msg[i])
		{
			if (it->msg[i] == '\n' || j == pane->dimension[1] - pane->padding[RIGHT] - pane->padding[LEFT])
			{
				j = 0;
				cursor[0] += 1;
			}
			else
			{
				mvwaddch(pane->win, cursor[0], cursor[1], it->msg[i]);
				cursor[1] += 1;
				++j;
			}
			++i;
		}
		it = it->next;
	}
}

void		libcurses_refresh_panes(t_screen *screen)
{
	t_panelist	*it;

	it = screen->panes;
	while (it != NULL)
	{
		if (it->pane)
		{
			if ((it->pane->flags & PANE_OUTPUT) && it->pane->inputs)
				libcurses_print(it->pane);
			else if ((it->pane->flags & PANE_INPUT))
				werase(it->pane->win);
			wrefresh(it->pane->win);
		}
		it = it->next;
	}
}
