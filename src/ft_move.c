/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:44:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/24 08:16:19 by lreznak-         ###   ########.fr       */
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
	if (arg->is_current == 1)
	{
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row), STDIN_FILENO);
		ft_putstr_fd(standstr, 0);
		ft_putstr_fd(arg->name, 0);
		ft_putstr_fd(stendstr, 0);
	}
	else
	{
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row), STDIN_FILENO);
		ft_putstr_fd(arg->name, 0);

	}
}

void	move_right(t_arg *arg)
{
	char buf[1024];
	char *gotostr;
	char *standstr;
	char *stendstr;

	tgetent(buf, getenv("TERM"));
	gotostr = tgetstr("cm", NULL);
	standstr = tgetstr("so", NULL);
	stendstr = tgetstr("se", NULL);
	// if (arg->is_selected == 1)
	{
		ft_putstr_fd(tgoto(gotostr, arg->next->col, arg->next->row), STDIN_FILENO);
		ft_putstr_fd(standstr, 0);
		ft_putstr_fd(arg->next->name, 0);
		ft_putstr_fd(stendstr, 0);
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row), STDIN_FILENO);
		ft_putstr_fd(arg->name, 0);
	}
}

void	move_left(t_arg *arg)
{
	char buf[1024];
	char *gotostr;
	char *standstr;
	char *stendstr;

	tgetent(buf, getenv("TERM"));
	gotostr = tgetstr("cm", NULL);
	standstr = tgetstr("so", NULL);
	stendstr = tgetstr("se", NULL);
	// if (arg->is_selected == 1)
	{
		ft_putstr_fd(tgoto(gotostr, arg->prev->col, arg->prev->row), 0);
		ft_putstr_fd(standstr, 0);
		ft_putstr_fd(arg->prev->name, 0);
		ft_putstr_fd(stendstr, 0);
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row), 0);
		ft_putstr_fd(arg->name, 0);
	}
}
