/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses_get_key_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:01:54 by marene            #+#    #+#             */
/*   Updated: 2016/04/04 13:49:54 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcurses.h"

static int				create_keycode(t_keycode **keycode, char key, key_fct code)
{
	*keycode = malloc(sizeof(t_keycode));
	if (*keycode != NULL)
	{
		keycode->key = key;
		keycode->f = code;
		return (LIBCURSES_OK);
	}
	return (LIBCURSES_NOK);
}

const t_keycode			**libcurses_get_key_map(void)
{
	static t_keycode	**map = NULL;
	const int			map_size = 6;

	if (map == NULL)
	{
		map = malloc(sizeof(t_keycode*) * (map_size + 1));
		map[map_size] = NULL;
		create_keycode(&(map[0]), '\n', libcurses_key_return);
		create_keycode(&(map[0]), 127, libcurses_key_delete);
		create_keycode(&(map[0]), 127, libcurses_key_delete);
	}
}
