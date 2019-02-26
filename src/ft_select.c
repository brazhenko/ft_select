/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 05:37:29 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/26 07:55:17 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void	set_keypress(int status)
{
	static struct termios stored_settings;
	static struct termios new_settings;

	if (status)
		tcgetattr(0, &stored_settings);
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	if (status)
		tcsetattr(0,TCSANOW,&new_settings);
	else if (!status)
	{
		tcsetattr(0, TCSANOW, &stored_settings);

	}
}

void	init_window(int status)
{

	char buf[1024];
	char *termtype=getenv("TERM");
	char *clstr;
	char *test2;
	char *test3;
	int ok;

	ok = tgetent(buf, termtype);
	if (status)
	{

//		char *test1 = tgetstr("cl", 0); /* очистка экрана */
//
//		char *clstr = tgetstr("ti", 0); /* запуск терминала */
//		char *test2 = tgetstr("vi", 0); /* Невидимый курсор */
//		char *test3 = tgetstr("nd", 0);
		tputs(TI, 1, putchar);
		tputs(VI, 1, putchar);
		tputs(CL, 1, putchar);
	}
	else
	{
		tputs(TE, 1, putchar);
		tputs(VE, 1, putchar);
		tputs(CL, 1, putchar);
	}

	// printf("%s%s%s\n", clstr, test1, test2);
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
	char 	cur_dir[2048] = ".";

	if (ac < 2)
		print_usage();
	ft_strcat(cur_dir, "/");
	//lst = make_t_arg_lst(av + 1, cur_dir);
	init_window(1);
	//print_all_args(lst);
	lst = read_directory(".");
	while (1)
	{
		set_keypress(1);
		read(STDIN_FILENO, &key, 8);
		if (key == KEY_ESC)
			ft_select_exit();
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
			lst = read_directory(cur_dir);
			ft_strcat(cur_dir, "/");
		}
		else if (key == KEY_BACKSPACE)
		{
			ft_strcat(cur_dir, "..");
			lst = read_directory(cur_dir);
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