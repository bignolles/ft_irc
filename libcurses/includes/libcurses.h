/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcurses.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:40:35 by marene            #+#    #+#             */
/*   Updated: 2016/03/16 12:53:50 by marene           ###   ########.fr       */
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

# define LIBCURSES_OK	0
# define LIBCURSES_NOK	1

# define PANE_BOXED		1
# define PANE_INPUT		2
# define PANE_OUTPUT	4
# define PANE_IO		(PANE_INPUT | PANE_OUTPUT)

typedef struct			s_input
{
	char			*msg;
	int				id;
	struct s_input	*next;
}						t_input;

typedef struct			s_pane
{
	char			*name;
	int				id;
	int				pos[2];
	int				dimension[2];
	int				padding[4];
	unsigned int	flags;
	WINDOW			*win;
	t_input			*inputs;
	int				input_id;
	int				max_input_id;
}						t_pane;

typedef struct			s_panelist
{
	t_pane					*pane;
	struct s_panelist		*next;
}						t_panelist;

typedef struct			s_screen
{
	t_panelist		*panes;
}						t_screen;

t_screen				*libcurses_init(void);
t_pane					*libcurses_add_pane(t_screen *screen, char *pane_name, unsigned int flags, int *dimension, int *padding);
t_pane					*libcurses_create_pane(char *pane_name, unsigned int flags, int *pos, int *dimension);
t_pane					*libcurses_get_pane_by_name(t_screen *screen, char *name);
t_pane					*libcurses_get_pane_by_id(t_screen *screen, int id);
void					libcurses_destruct_pane(t_pane **pane);
void					libcurses_refresh_panes(t_screen *screen);
void					libcurses_set_pos(int *pos, int lines, int cols);
int						libcurses_add_input_by_name(t_screen *screen, char *input, char *name);
int						libcurses_add_input_by_id(t_screen *screen, char *input, int id);
void					libcurses_destruct_screen(t_screen **screen);

#endif
