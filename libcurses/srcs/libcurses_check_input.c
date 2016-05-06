/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_check_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 10:25:12 by marene            #+#    #+#             */
/*   Updated: 2016/05/05 14:59:53 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcurses.h"

int			libcurses_check_input(t_screen *screen)
{
	t_pane		*input;

	input = libcurses_get_pane_by_flags(screen, PANE_INPUT);
	if (input != NULL)
	{
		wmove(input->win, input->dimension[0] / 2, input->padding[LEFT]
				+ input->cursor);
		wrefresh(input->win);
		return (LIBCURSES_OK);
	}
	return (LIBCURSES_NOK);
}
