/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_add_in_pane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:24:46 by marene            #+#    #+#             */
/*   Updated: 2016/03/11 17:09:52 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

t_pane		*libcurses_add_in_pane(t_screen *screen, char *pane_name, unsigned int flags, int *pos, int *dimension)
{
	t_pane		*new_pane;

	new_pane = NULL;
	if (!(flags & PANE_OUTPUT))
	{
		new_pane = create_pane(pane_name, flags, dimension, padding);
		if (new_pane != NULL)
		{
		}
	}
	return (new_pane);
}
