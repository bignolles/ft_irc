/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 19:01:52 by marene            #+#    #+#             */
/*   Updated: 2015/05/06 17:37:35 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_epur_len(char *s)
{
	int		i;
	int		len;
	char	prev;

	i = 0;
	len = 0;
	prev = '\t';
	while (s[i])
	{
		if ((!ft_iswhite(prev) && ft_iswhite(s[i])) || !ft_iswhite(s[i]))
			++len;
		prev = s[i];
		++i;
	}
	return (len);
}

static int		insert_epur(char *epur, char c, char prev)
{
	if (!ft_iswhite(c))
		*epur = c;
	else if (!ft_iswhite(prev) && ft_iswhite(c))
		*epur = ' ';
	else
		return (0);
	return (1);
}

char			*ft_epurstr(char *s)
{
	char	*epur;
	int		epur_len;
	int		i;
	int		j;
	char	prev;

	i = 0;
	j = 0;
	epur_len = ft_epur_len(s);
	if ((epur = (char *)malloc(sizeof(char) * (epur_len + 1))) != NULL)
	{
		prev = ' ';
		while (s[i])
		{
			if (insert_epur(&epur[i], s[i], prev))
				++j;
			prev = s[i];
			++i;
		}
	}
	epur[epur_len] = '\0';
	return (epur);
}
