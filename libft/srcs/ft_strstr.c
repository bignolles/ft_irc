/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:30:57 by marene            #+#    #+#             */
/*   Updated: 2014/10/14 12:41:57 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	if (!s2[0] || !s2)
		return ((char*)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
			while (s1[i + j] && s1[i + j] == s2[j])
			{
				if (!s2[j + 1])
					return ((char*)&s1[i]);
				j++;
			}
		i++;
	}
	return (NULL);
}
