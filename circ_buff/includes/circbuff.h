/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circbuff.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:24:50 by marene            #+#    #+#             */
/*   Updated: 2016/02/25 16:28:55 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCBUFF_H
# define CIRCBUFF_H

# define CIRCBUFF_BUFF_SIZE		1024

typedef struct		s_circbuff
{
	char	*buff;
	int		read;
	int		write;
	int		tmp;
}					t_circbuff;

#endif
