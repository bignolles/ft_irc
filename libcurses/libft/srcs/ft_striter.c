/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:31:12 by marene            #+#    #+#             */
/*   Updated: 2014/10/14 12:36:44 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_striter(char *s, void (*f) (char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		(*f)(&s[i]);
		i++;
	}
}
