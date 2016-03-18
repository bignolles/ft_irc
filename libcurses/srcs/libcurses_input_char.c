/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_input_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 18:13:26 by marene            #+#    #+#             */
/*   Updated: 2016/03/18 18:35:47 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcurses.h"

char		libcurses_input_char(t_screen *screen)
{
	t_pane		*input_p;

	input_p = libcurses_get_pane_by_flags(screen, PANE_INPUT);
	if (input_p != NULL)
	{
		
	}
	return ('\0');
}
