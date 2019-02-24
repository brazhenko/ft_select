/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 04:40:33 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 05:29:49 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg		*new_t_arg(char *name)
{
	t_arg	*new;

	new = (t_arg *)malloc(sizeof(t_arg));
	new->prev = NULL;
	new->next = NULL;
	new->namelen = ft_strlen(name);
	new->name = ft_strcpy(ft_strnew(new->namelen), name);
	return (new);
}

t_arg		*make_t_arg_lst(char **args)
{
	t_arg	*node;
	t_arg	*node_cpy;
	int 	i;

	i = 0;
	node = new_t_arg(args[i++]);
	node_cpy = node;
	while (args[i])
	{
		node->next = new_t_arg(args[i]);
		node->next->prev = node;
		node = node->next;
		i++;
	}
	return (node_cpy);
}
