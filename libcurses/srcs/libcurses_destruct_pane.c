/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_destruct_pane.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:38:50 by marene            #+#    #+#             */
/*   Updated: 2016/05/05 15:00:19 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libcurses.h"

void		libcurses_destruct_pane(t_pane **pane)
{
	free((*pane)->name);
	free((*pane)->win);
	free(*pane);
	*pane = NULL;
}
