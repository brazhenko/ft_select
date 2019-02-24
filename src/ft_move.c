/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:44:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/24 10:44:50 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_arg(t_arg *arg)
{
	char buf[1024];

	if (!arg)
		return ;
	tgetent(buf, getenv("TERM"));
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), arg->col, arg->row), STDIN_FILENO);
	if (arg->is_current)
		ft_putstr_fd(tgetstr("us", NULL), 0);
	if (arg->is_selected)
		ft_putstr_fd(tgetstr("so", NULL), 0);
	ft_putstr_fd(arg->name, 0);
	ft_putstr_fd(tgetstr("ue", NULL), 0);
	ft_putstr_fd(tgetstr("se", NULL), 0);
}

void	print_all_args(t_arg *arg)
{
	if (!arg)
		return ;
	while (!arg->is_begin)
		arg = arg->next;
	do
	{
		print_arg(arg);
		arg = arg->next;
	}
	while (!arg->is_begin);
}

void	move_arg(t_arg **arg, char *direction)
{
	(*arg)->is_current = 0;
	print_arg(*arg);
	if (ft_strequ("prev", direction))
		*arg = (*arg)->prev;
	if (ft_strequ("next", direction))
		*arg = (*arg)->next;
	(*arg)->is_current = 1;
	print_arg(*arg);
}
