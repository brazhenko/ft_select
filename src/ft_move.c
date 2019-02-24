/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:44:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/24 06:47:40 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

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
	if (arg->is_selected == 1)
	{
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row), 0);
		ft_putstr_fd(standstr, 0);
		ft_putstr_fd("%s", 0);
		ft_putstr_fd(stendstr, 0);
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row - 1), 0);
		ft_putstr_fd("%s", 0);
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
	if (arg->is_selected == 1)
	{
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row), 0);
		ft_putstr_fd(standstr, 0);
		ft_putstr_fd("%s", 0);
		ft_putstr_fd(stendstr, 0);
		ft_putstr_fd(tgoto(gotostr, arg->col, arg->row + 1), 0);
		ft_putstr_fd("%s", 0);
	}
}
