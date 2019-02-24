/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:44:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/24 10:09:22 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_arg(t_arg *arg)
{
	char buf[1024];
	char *gotostr;
	char *standstr;
	char *stendstr;

	tgetent(buf, getenv("TERM"));
	gotostr = tgetstr("cm", NULL);
	standstr = tgetstr("us", NULL); /*so se */
	stendstr = tgetstr("ue", NULL);
	if (arg->is_current)
	{
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row), STDIN_FILENO);
		ft_putstr_fd(standstr, 0);
		ft_putstr_fd(arg->name, 0);
	}
	if (arg->is_selected)
	{
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row), STDIN_FILENO);
		ft_putstr_fd(tgetstr("so", NULL), 0);
		ft_putstr_fd(arg->name, 0);
	}
	if (!arg->is_selected && !arg->is_current)
	{
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row), STDIN_FILENO);
		ft_putstr_fd(arg->name, 0);

	}
	ft_putstr_fd(stendstr, 0);
	ft_putstr_fd(tgetstr("se", NULL), 0);
}

void	move_next(t_arg **arg)
{
	char buf[1024];
	char *gotostr;
	char *standstr;
	char *stendstr;

	tgetent(buf, getenv("TERM"));
	gotostr = tgetstr("cm", NULL);
	standstr = tgetstr("us", NULL);
	stendstr = tgetstr("ue", NULL);

	(*arg)->is_current = 0;
	print_arg(*arg);
	*arg = (*arg)->next;
	(*arg)->is_current = 1;
	print_arg(*arg);
}

void	move_prev(t_arg **arg)
{
	char buf[1024];
	char *gotostr;
	char *standstr;
	char *stendstr;

	tgetent(buf, getenv("TERM"));
	gotostr = tgetstr("cm", NULL);
	standstr = tgetstr("us", NULL);
	stendstr = tgetstr("ue", NULL);

	(*arg)->is_current = 0;
	print_arg(*arg);
	*arg = (*arg)->prev;
	(*arg)->is_current = 1;
	print_arg(*arg);
}
