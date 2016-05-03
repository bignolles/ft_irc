/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:11:09 by marene            #+#    #+#             */
/*   Updated: 2016/05/03 16:36:07 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

t_keycode			g_keycodes[KEYCODES_NB] = {
	{KEY_DC, handle_key_dc},
	{KEY_LEFT, handle_key_left},
	{KEY_RIGHT, handle_key_right},
	{KEY_UP, NULL},
	{KEY_DOWN, NULL},
	{KEY_BACKSPACE, handle_key_dc},
	{127, handle_key_dc},
	{'\n', handle_key_enter},
};

static int			init(int i)
{
	static int		init = 0;
	int				ret;

	ret = init;
	if (i < 0)
		init = 0;
	else
		init = 1;
	return (ret);
}

void				libcurses_reinit(void)
{
	echo();
	endwin();
	init(-1);
}

t_screen			*libcurses_init(void)
{
	t_screen		*ret;

	ret = malloc(sizeof(t_screen));
	if (ret != NULL)
	{
		if (!init(0))
		{
			initscr();
			noecho();
		}
		ret->panes = malloc(sizeof(t_panelist));
		if (ret->panes == NULL)
		{
			free(ret);
			ret = NULL;
		}
		else
		{
			ret->panes->next = NULL;
			ret->panes->pane = NULL;
		}
	}
	return (ret);
}
