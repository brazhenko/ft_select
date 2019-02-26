/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 05:37:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/26 14:18:41 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_keypress(int status)
{
	static struct termios stored_settings;
	static struct termios new_settings;
	static int used = 0;

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
		tcsetattr(0,TCSANOW,&new_settings);
	else if (!status)
		tcsetattr(0, TCSANOW, &stored_settings);
}


void	init_window(int status)
{

	char buf[1024];
	char *termtype=getenv("TERM");
	int ok;

	ok = tgetent(buf, termtype);
	ft_putstr(CL);
	if (status == 1)
	{
		ft_putstr(VI);
		ft_putstr(VI);
//		tputs(TI, 1, putchar);	/* запуск терминала */
//		tputs(VI, 1, putchar);	/* Невидимый курсор */
	}
	else
	{
		ft_putstr(TE);
		ft_putstr(VE);
//		tputs(TE, 1, putchar);
//		tputs(VE, 1, putchar);
	}
}

void			print_usage(void)
{
	write(1, "usage: ./ft_select [arg1] [arg2] [arg3] ...\n", 45);
	exit(EXIT_SUCCESS);
}

extern char		**environ;


int				main(int ac, char **av, char **en)
{
	long	key = 0;
	t_arg	*lst;
	char 	cur_dir[2048] = "./";

	signal(SIGINT, ft_select_exit);
//	signal(SIGWINCH, t_arg_resize_decorator(lst));
	if (ac < 2)
		print_usage();
	lst = make_t_arg_lst(av + 1);
	print_all_args(lst);
	while (1)
	{
		set_keypress(1);
		read(STDIN_FILENO, &key, 8);
		if (key == KEY_ESC)
			ft_select_exit(1);
		else if (key == KEY_DOWN)
			move_arg(&lst, "next");
		else if (key == KEY_UP)
			move_arg(&lst, "prev");
		else if (key == KEY_SPC)
		{
			lst->is_selected = ~lst->is_selected;
			print_arg(lst);
		}
		else if (key == KEY_TAB)
		{
			ft_strcat(cur_dir, lst->name);
			lst = make_t_arg_lst(read_directory(cur_dir));
			ft_strcat(cur_dir, "/");

			print_all_args(lst);
		}
		else if (key == KEY_BACKSPACE)
		{
			ft_strcat(cur_dir, "..");
			lst = make_t_arg_lst(read_directory(cur_dir));
			print_all_args(lst);
			ft_strcat(cur_dir, "/");
		}
		else if (key == KEY_DEL)
		{
			lst = delete_t_arg(lst);
		}
		else if (key == KEY_ENTER)
		{
			return_value(lst);
			exit (0);
		}
		else if (key == 1111111)
			exit(0);
		key = 0;
	}
}