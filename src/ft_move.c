/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 06:44:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/26 14:31:44 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_color(char *name)
{
	struct stat buf;

	lstat(name, &buf);
	if (S_ISDIR(buf.st_mode))
	{
		ft_putstr_fd("\x1B[34m", 0);
		ft_putstr_fd(name, 0);
		ft_putstr_fd("\x1B[0m", 0);
	}
	else if (S_ISLNK(buf.st_mode))
	{
		ft_putstr_fd("\x1B[35m", 0);
		ft_putstr_fd(name, 0);
		ft_putstr_fd("\x1B[0m", 0);
	}
	else if (!access(name, 1))
	{
		ft_putstr_fd("\x1B[31m", 0);
		ft_putstr_fd(name, 0);
		ft_putstr_fd("\x1B[0m", 0);
	}
	else
		ft_putstr_fd(name, 0);
}

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
	print_color(arg->name);
	ft_putstr_fd(tgetstr("ue", NULL), 0);
	ft_putstr_fd(tgetstr("se", NULL), 0);
}

void	print_all_args(t_arg *arg)
{

	if (!arg)
		return ;
	set_keypress(1);
	init_window(1);
	if (!t_arg_resize(arg))
	{
		write(1, "plz make window bigger\n", 24);
		return ;
	}
	while (!arg->is_begin)
		arg = arg->next;
	print_arg(arg);
	arg = arg->next;
	while (!arg->is_begin)
	{
		print_arg(arg);
		arg = arg->next;
	}
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
