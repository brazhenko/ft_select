/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_configure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:36:45 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/26 19:38:05 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			set_keypress(int status)
{
	static struct termios	stored_settings;
	static struct termios	new_settings;
	static int				used = 0;

	if (!used)
	{
		used++;
		tcgetattr(0, &stored_settings);
	}
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	if (status)
		tcsetattr(0, TCSANOW, &new_settings);
	else if (!status)
		tcsetattr(0, TCSANOW, &stored_settings);
}

void			init_window(int status)
{
	char	buf[1024];
	char	*termtype;
	int		ok;

	termtype = getenv("TERM");
	ok = tgetent(buf, termtype);
	if (status == 1)
	{
		ft_putstr(VI);
		ft_putstr(VI);
	}
	else
	{
		ft_putstr(TE);
		ft_putstr(VE);
	}
	ft_putstr(CL);
}
