/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_input_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:13:26 by marene            #+#    #+#             */
/*   Updated: 2016/05/03 16:47:59 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

extern t_keycode	g_keycodes[KEYCODES_NB];

char				libcurses_input_char(t_screen *screen)
{
	t_pane		*input_p;
	int			ch;
	int			i;

	i = 0;
	input_p = libcurses_get_pane_by_flags(screen, PANE_INPUT);
	if (input_p != NULL && input_p->input_msg_len < LIBCURSES_MAX_INPUT - 1)
	{
		ch = wgetch(input_p->win);
		while (i < KEYCODES_NB)
		{
			if (g_keycodes[i].keycode == ch && g_keycodes[i].f != NULL)
				return ((g_keycodes[i].f)(input_p));
			++i;
		}
/*
		if (ch == KEY_ENTER)
		{
			werase(input_p->win);
			ft_bzero(input_p->input_msg, input_p->input_msg_len);
			input_p->input_msg_len = 0;
			if ((input_p->flags & PANE_BOXED))
				box(input_p->win, ACS_VLINE, ACS_HLINE);
			ch = '\n';
		}
		else if (ch == KEY_BACKSPACE || ch == KEY_DC)
		{
			if (input_p->input_msg_len > 0)
			{
				mvwdelch(input_p->win, input_p->dimension[0] / 2, input_p->padding[LEFT] + input_p->cursor - 1);
				input_p->input_msg_len -= 1;
				input_p->input_msg[input_p->input_msg_len] = '\0';
			}
		}
		else
		{
*/
			input_p->input_msg[input_p->input_msg_len] = ch;
			input_p->input_msg_len += 1;
			mvwaddch(input_p->win, input_p->dimension[0] / 2, input_p->padding[LEFT] + input_p->cursor, ch);
			input_p->cursor += 1;
//		}
		return (ch);
	}
	return ('\0');
}
