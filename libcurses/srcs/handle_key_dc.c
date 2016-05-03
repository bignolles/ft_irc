/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_dc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:00:13 by marene            #+#    #+#             */
/*   Updated: 2016/05/03 16:38:07 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libcurses.h"

char		handle_key_dc(t_pane *p)
{
	if (p->input_msg_len > 0)
	{
		mvwdelch(p->win, p->dimension[0] / 2, p->padding[LEFT] + p->cursor);
		p->input_msg_len -= 1;
		p->input_msg[p->input_msg_len] = '\0';
		p->cursor -= 1;
	}
	return (0x08);
}
