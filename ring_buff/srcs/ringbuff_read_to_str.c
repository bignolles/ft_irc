/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_read_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:47:12 by marene            #+#    #+#             */
/*   Updated: 2016/05/06 15:19:01 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ringbuff.h"

static int		check_terminal_str(t_ringbuff *buff, char *str, int i,
		char **tmp)
{
	int		j;
	int		read_space;

	j = 0;
	read_space = ringbuff_get_read_space(buff);
	while (str[j] && i + j < read_space
			&& buff->buff[(buff->start + i + j) % buff->len] == str[j])
		++j;
	if (!str[j])
	{
		if ((*tmp = malloc(sizeof(char) * (i + j + 1))))
		{
			(*tmp)[i + j] = '\0';
			return (ringbuff_read(buff, *tmp, i + j));
		}
	}
	return (-1);
}

int				ringbuff_read_to_str(t_ringbuff *buff, char **tmp, char *str)
{
	int		i;
	int		j;
	int		it;
	int		read_space;

	i = 0;
	read_space = ringbuff_get_read_space(buff);
	while (i < read_space)
	{
		it = (buff->start + i) % buff->len;
		if (buff->buff[it] == str[0])
		{
			if ((j = check_terminal_str(buff, str, i, tmp)) != -1)
				return (j);
			i += j;
		}
		else
			++i;
	}
	return (0);
}
