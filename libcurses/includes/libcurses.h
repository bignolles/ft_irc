/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:40:35 by marene            #+#    #+#             */
/*   Updated: 2016/03/11 17:16:31 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBCURSES_H
# define FT_LIBCURSES_H

/*
** LIBCURSES
** libcurses is a simple ncurses overlay to manipulate several windows,
** write in them, and more generally use them around with lesser efforts
** than actually using ncurses
*/

# include <ncurses.h>

# define LEFT			0
# define RIGHT			1
# define TOP			2
# define BOTTOM			3

# define LIBCURSE_OK	0
# define LIBCURSE_NOK	1

# define PANE_BOXED		1
# define PANE_INPUT		2
# define PANE_OUTPUT	4

typedef struct			s_pane
{
	char			*name;
	int				id;
	int				pos[2];
	int				dimension[2];
	int				padding[4];
	unsigned int	flags;
	WINDOW			*win;
}						t_pane;

typedef struct			s_screen
{
	t_pane			*in_pane;
	t_pane			*out_pane;
}						t_screen;

t_screen				*libcurses_init(void);
t_pane					*libcurses_add_in_pane(t_screen *screen, char *pane_name, unsigned int flags, int *dimension, int *padding);
t_pane					*libcurses_create_pane(char *pane_name, unsigned int flags, int *pos, int *dimension);

#endif
