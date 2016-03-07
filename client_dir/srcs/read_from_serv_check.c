/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_serv_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 18:31:36 by marene            #+#    #+#             */
/*   Updated: 2016/03/07 10:33:54 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "client.h"

void		read_from_serv_check(t_env *env)
{
	int		ret;
	char	*to_print;

	to_print = NULL;
	while ((ret = ringbuff_read_to_str(env->buf_read, &to_print, IRC_END)) > 0)
	{
		if (ft_strlen(to_print) > 2) // if there is something else than a mere "\n\r" to print. Find a cleaner way to achieve it server side by
			// avoiding sending bare "\n\r" packets of data
		{
			write(1, to_print, ret - 2);
			ft_putchar('\n');
		}
		to_print = NULL;
	}
}