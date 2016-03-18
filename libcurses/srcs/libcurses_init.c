/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:11:09 by marene            #+#    #+#             */
/*   Updated: 2016/03/14 16:57:54 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	# include <stdio.h>

#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

t_screen		*libcurses_init(void)
{
	t_screen		*ret;
	static char		init = 0;

	ret = malloc(sizeof(t_screen));
	if (ret != NULL)
	{
		if (!init)
		{
			initscr();
			init = 1;
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