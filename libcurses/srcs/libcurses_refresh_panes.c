/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_refresh_panes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:08:30 by marene            #+#    #+#             */
/*   Updated: 2016/05/06 13:07:11 by marene           ###   ########.fr       */
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

static void	print(t_pane *pane, t_input *it, int line)
{
	int		cursor[2];
	int		i;

	i = 0;
	cursor[0] = line;
	cursor[1] = pane->padding[LEFT];
	while (it->msg[i])
	{
		if (it->msg[i] == '\n' || cursor[1] == pane->dimension[1]
				- pane->padding[RIGHT] - pane->padding[LEFT])
		{
			cursor[0] += 1;
			cursor[1] = pane->padding[LEFT] - 1;
		}
		else if (cursor[0] > 0)
		{
			mvwaddch(pane->win, cursor[0], cursor[1], it->msg[i]);
		}
		cursor[1] += 1;
		++i;
	}
}

void		libcurses_print(t_pane *pane)
{
	t_input		*it;
	int			line;

	line = pane->dimension[0];
	it = pane->inputs;
	while (it != NULL)
	{
		line -= (get_lines_nb(it->msg, pane->dimension[1] - pane->padding[RIGHT]
					- pane->padding[LEFT]) + 1);
		print(pane, it, line);
		it = it->next;
	}
}

t_pane		*get_input(t_screen *screen)
{
	t_panelist	*it;

	it = screen->panes;
	while (it != NULL)
	{
		if (it->pane && (it->pane->flags & PANE_INPUT))
			return (it->pane);
		else
			it = it->next;
	}
	return (NULL);
}

void		libcurses_refresh_panes(t_screen *screen)
{
	t_panelist	*it;
	t_pane		*in;

	it = screen->panes;
	while (it != NULL)
	{
		if (it->pane)
		{
			werase(it->pane->win);
			if ((it->pane->flags & PANE_BOXED))
				box(it->pane->win, ACS_VLINE, ACS_HLINE);
			if ((it->pane->flags & PANE_OUTPUT) && it->pane->inputs)
				libcurses_print(it->pane);
			if ((it->pane->flags & PANE_INPUT))
			{
				mvwaddstr(it->pane->win, it->pane->dimension[0] / 2,
						it->pane->padding[LEFT], it->pane->input_msg);
			}
			wrefresh(it->pane->win);
		}
		it = it->next;
	}
	in = get_input(screen);
	if (in != NULL)
		wmove(in->win, in->dimension[0] / 2, in->cursor + in->padding[LEFT]);
}
