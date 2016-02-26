/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuff_read_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 19:47:12 by marene            #+#    #+#             */
/*   Updated: 2016/02/26 20:14:06 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ringbuff.h"

int					ringbuff_read_to_str(t_ringbuff *buff, char **tmp, char *str)
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
			j = 0;
			while (str[j] && i + j < read_space
					&& buff->buff[(buff->start + i + j) % buff->len] == str[j])
			{
				++j;
			}
			if (!str[j])
			{
				*tmp = malloc(sizeof(char) * (i + 1));
				if (*tmp == NULL)
					return (-1);
				return (ringbuff_read(buff, *tmp, i));
			}
			i += j;
		}
		else
			++i;
	}
	return (0);
}