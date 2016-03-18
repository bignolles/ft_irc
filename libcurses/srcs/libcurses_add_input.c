/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 10:38:23 by marene            #+#    #+#             */
/*   Updated: 2016/03/18 12:44:13 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libcurses.h"

t_input		*create_input(char *input, int id)
{
	t_input		*ret;
	char		*cpy;

	ret = malloc(sizeof(t_input));
	cpy = ft_strtrim(input);
	if (ret != NULL && cpy != NULL)
	{
		ret->id = id;
		ret->msg = cpy;
		ret->next = NULL;
	}
	else
	{
		free(cpy);
		free(ret);
	}
	return (ret);
}

int			add_input(t_pane *pane, char *input)
{
	t_input		*new_input;

	new_input = create_input(input, pane->max_input_id);
	if (new_input != NULL)
	{
		pane->max_input_id += 1;
		new_input->next = pane->inputs;
		pane->inputs = new_input;
		return (LIBCURSES_OK);
	}
	else
		return (LIBCURSES_NOK);
}

int			libcurses_add_input_by_name(t_screen *screen, char *input, char *name)
{
	t_panelist	*it;
	int			all;

	it = screen->panes;
	all = ft_strequ(name, "all");
	while (it != NULL)
	{
		if (it->pane && (all || ft_strequ(it->pane->name, name)))
		{
			if (add_input(it->pane, input) == LIBCURSES_NOK)
				return (LIBCURSES_NOK);
		}
		it = it->next;
	}
	return (LIBCURSES_OK);
}

int			libcurses_add_input_by_id(t_screen *screen, char *input, int id)
{
	t_panelist	*it;
	int			all;

	it = screen->panes;
	all = (id == -1);
	while (it != NULL)
	{
		if (it->pane && (all || it->pane->id == id))
		{
			if (add_input(it->pane, input) == LIBCURSES_NOK)
				return (LIBCURSES_NOK);
			else if (!all)
				return (LIBCURSES_OK);
		}
		it = it->next;
	}
	return (LIBCURSES_OK);
}
