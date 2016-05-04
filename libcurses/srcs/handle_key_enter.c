/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_enter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:21:59 by marene            #+#    #+#             */
/*   Updated: 2016/05/04 15:21:33 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libcurses.h"

char		*handle_key_enter(t_pane *p)
{
	char	*ret;

	werase(p->win);
	ret = ft_strdup(p->input_msg);
	ft_bzero(p->input_msg, p->input_msg_len);
	p->input_msg_len = 0;
	p->cursor = 0;
	if ((p->flags & PANE_BOXED))
		box(p->win, ACS_VLINE, ACS_HLINE);
	return (ret);
}
