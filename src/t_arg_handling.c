/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 04:40:33 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 13:22:12 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg		*new_t_arg(char *name, char *cur_dir)
{
	t_arg	*new;

	new = (t_arg *)malloc(sizeof(t_arg));
	new->prev = NULL;
	new->next = NULL;
	new->namelen = ft_strlen(name);
	new->name = ft_strcpy(ft_strnew(new->namelen), name);
	new->col = 1;
	new->is_selected = 0;
	new->is_current = 0;
	return (new);
}

void		delete_t_arg(t_arg **arg)
{
	if (!(*arg))
		return ;
	ft_putstr_fd(tgetstr("cl",0), 0);
	(*arg)->prev->next = (*arg)->next;
	(*arg)->next->prev = (*arg)->prev;
	(*arg) = (*arg)->prev == (*arg) ? NULL : (*arg)->prev;
	(*arg)->is_current = 1;
	print_all_args(*arg);
}

t_arg		*make_t_arg_lst(char **args, char *cur_dir)
{
	t_arg	*node;
	t_arg	*node_cpy;
	int 	i;

	i = 0;
	node = new_t_arg(args[i], cur_dir);
	node->row = i;
	node_cpy = node;
	node->is_current = node->is_begin = 1;
	i++;
	while (args[i])
	{

		node->next = new_t_arg(args[i], cur_dir);
		node->next->prev = node;
		node = node->next;
		node->row = i;
		i++;
	}
	node->next = node_cpy;
	node->next->prev = node;
	return (node_cpy);
}
