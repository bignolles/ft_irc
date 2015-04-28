/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 18:21:45 by marene            #+#    #+#             */
/*   Updated: 2015/04/28 18:22:13 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

t_channel	*create_channel(int id, char *name)
{
	t_channel	*ret;

	if ((ret = (t_channel *)malloc(sizeof(t_channel))) != NULL)
	{
		ret->id = id;
		ret->name = ft_strdup(name);
		ret->next = NULL;
	}
	return (ret);
}

int			add_channel(t_env *env, t_channel *new)
{
	t_channel	*tmp;

	tmp = env->chans;
	while (tmp)
	{
		if (tmp->id == new->id ||
		(tmp->name && ft_strcmp(tmp->name, new->name)) == 0)
			return (SERV_ERROR);
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return (SERV_OK);
		}
		tmp = tmp->next;
	}
	return (SERV_ERROR);
}
