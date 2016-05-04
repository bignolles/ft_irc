/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_input_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:13:26 by marene            #+#    #+#             */
/*   Updated: 2016/05/04 15:14:14 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

extern t_keycode	g_keycodes[KEYCODES_NB];

static void			insert_char(t_pane *p, char c)
{
	int		i;

	if (p->cursor < p->input_msg_len && p->input_msg_len < LIBCURSES_MAX_INPUT - 1)
	{
		i = p->input_msg_len;
		while (i >= p->cursor)
		{
			p->input_msg[i + 1] = p->input_msg[i];
			--i;
		}
		ft_putendl(p->input_msg);
	}
	if (p->input_msg_len < LIBCURSES_MAX_INPUT - 1)
	{
		p->input_msg[p->cursor] = c;
		p->input_msg_len += 1;
		p->cursor += 1;
		p->input_msg[p->input_msg_len] = '\0';
	}
}

char				*libcurses_input_char(t_screen *screen)
{
	t_pane		*p;
	int			ch;
	int			i;

	i = 0;
	p = libcurses_get_pane_by_flags(screen, PANE_INPUT);
	if (p != NULL && p->input_msg_len < LIBCURSES_MAX_INPUT - 1)
	{
		ch = wgetch(p->win);
		while (i < KEYCODES_NB)
		{
			if (g_keycodes[i].keycode == ch)
				return ((g_keycodes[i].f == NULL) ? '\0' : (g_keycodes[i].f)(p));
			++i;
		}
		insert_char(p, ch);
		werase(p->win);
		wrefresh(p->win);
		wmove(p->win, p->dimension[0] / 2, p->cursor + p->padding[LEFT]);
		waddstr(p->win, p->input_msg);
	}
	return (NULL);
}
