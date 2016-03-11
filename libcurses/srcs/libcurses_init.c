/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:11:09 by marene            #+#    #+#             */
/*   Updated: 2016/03/11 14:22:19 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libcurses.h"

t_screen		*libcurses_init(void)
{
	t_screen		*ret;

	ret = malloc(sizeof(t_screen));
	if (ret != NULL)
	{
		initscr();
		ret->pane = NULL;
	}
	return (ret);
}
