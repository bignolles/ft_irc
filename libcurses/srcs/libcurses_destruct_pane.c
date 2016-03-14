/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_destruct_pane.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:38:50 by marene            #+#    #+#             */
/*   Updated: 2016/03/14 12:46:06 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libcurses.h"

void		libcurses_destruct_pane(t_pane **pane)
{
	free((*pane)->name);
	free((*pane)->win);
	//free *pane->dimension et *pane->pos???
	free(*pane);
	*pane = NULL;
}
