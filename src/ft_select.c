/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 05:37:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/26 16:25:37 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg		*g_lst;
char		g_cur_dir[2048] = "./";

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
	ft_putstr(CL);
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
}

void			print_usage(void)
{
	write(1, "usage: ./ft_select [arg1] [arg2] [arg3] ...\n", 45);
	exit(EXIT_SUCCESS);
}

extern char		**environ;

void			print_all_args_handler(int n)
{
	print_all_args(g_lst);
}

int				main(int ac, char **av, char **en)
{
	long	key;

	signal(SIGINT, ft_select_exit);
	signal(SIGWINCH, print_all_args_handler);
	if (ac < 2)
		print_usage();
	g_lst = make_t_arg_lst(av + 1, NULL);
	print_all_args(g_lst);
	while (1)
	{
		set_keypress(1);
		key = 0;
		read(STDIN_FILENO, &key, 8);
		if (key == KEY_ESC)
			ft_select_exit(1);
		else if (key == KEY_DOWN)
			move_arg(&g_lst, "next");
		else if (key == KEY_UP)
			move_arg(&g_lst, "prev");
		else if (key == KEY_SPC)
		{
			g_lst->is_selected = ~g_lst->is_selected;
			print_arg(g_lst);
		}
		else if (key == KEY_TAB)
		{
			ft_strcat(g_cur_dir, g_lst->name);
			g_lst = make_t_arg_lst(read_directory(g_cur_dir), NULL);
			ft_strcat(g_cur_dir, "/");
			print_all_args(g_lst);
		}
		else if (key == KEY_BACKSPACE)
		{
			ft_strcat(g_cur_dir, "..");
			g_lst = make_t_arg_lst(read_directory(g_cur_dir), NULL);
			ft_strcat(g_cur_dir, "/");
			print_all_args(g_lst);
		}
		else if (key == KEY_DEL)
		{
			g_lst = delete_t_arg(g_lst);
		}
		else if (key == KEY_ENTER)
		{
			return_value(g_lst);
			exit(0);
		}
		else if (key == 1111111)
			exit(0);
	}
}
