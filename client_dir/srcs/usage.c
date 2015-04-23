/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 17:04:31 by marene            #+#    #+#             */
/*   Updated: 2014/11/02 17:25:07 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>
#include <libft.h>

void	usage(char *exname)
{
	ft_putstr("usage: ");
	ft_putstr(exname);
	ft_putendl(USAGE_MSG);
}
