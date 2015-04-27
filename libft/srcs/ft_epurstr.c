/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 19:01:52 by marene            #+#    #+#             */
/*   Updated: 2014/10/26 22:35:37 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_epur_len(char *s)
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

char		*ft_epurstr(char *s)
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
			if (!ft_iswhite(s[i]))
				epur[j] = s[i];
			else if (!ft_iswhite(prev) && ft_iswhite(s[i]))
				epur[j] = ' ';
			else
				--j;
			prev = s[i];
			++i;
			++j;
		}
	}
	epur[epur_len] = '\0';
	return (epur);
}
