/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_input_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:13:26 by marene            #+#    #+#             */
/*   Updated: 2016/03/21 17:09:21 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

char		libcurses_input_char(t_screen *screen, int cols)
{
	t_pane		*input_p;
	int			ch;

	input_p = libcurses_get_pane_by_flags(screen, PANE_INPUT);
	if (input_p != NULL)
	{
		ch = wgetch(input_p->win);
		if (ch == '\n')
		{
			werase(input_p->win);
			if ((input_p->flags & PANE_BOXED))
				box(input_p->win, ACS_VLINE, ACS_HLINE);
		}
		else if (ch == 127)
		{
			mvwdelch(input_p->win, input_p->dimension[0] / 2, input_p->padding[LEFT] + cols - 1);
		}
		else
		{
			mvwaddch(input_p->win, input_p->dimension[0] / 2, input_p->padding[LEFT] + cols, ch);
		}
		return (ch);
	}
	return ('\0');
}
