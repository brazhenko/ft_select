/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 01:34:34 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/26 12:14:31 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <term.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <signal.h>
/*
**	Defines of needed keys.
*/

# define KEY_BACKSPACE		127
# define KEY_DEL			2117294875
# define KEY_LEFT			4479771
# define KEY_UP				4283163
# define KEY_RIGHT			4414235
# define KEY_DOWN			4348699
# define KEY_ESC			27
# define KEY_TAB			9
# define KEY_SPC			32
# define KEY_ENTER			10

/*
**	Defines of tgetstr arguments
*/

# define SO (tgetstr("so", NULL)) //начало выделения
# define SE (tgetstr("se", NULL)) //конец выделения
# define CL (tgetstr("cl", NULL)) //чистит экран
# define CM (tgetstr("cm", NULL)) //перемещение курсора
# define VE (tgetstr("ve", NULL)) //видимый курсов
# define VI (tgetstr("vi", NULL)) //невидимый курсор
# define US (tgetstr("us", NULL)) //начало подчеркивания
# define TE (tgetstr("te", NULL)) //конец программы
# define TI (tgetstr("ti", NULL)) //начало программs

/*
**			t_arg (aka struct s_arg):
**
**			col, row - coordinates at the output
** 			type: 0 - usual file or smth else, 1 - directory, 2 - binary, 3 - symlink
**			is_selected - flag of the
*/

typedef struct s_arg		t_arg;
typedef struct dirent		t_dirent;

struct		s_arg
{
	t_arg	*prev;
	t_arg	*next;

	int		col;
	int		row;
	int		type;
	int		is_selected;
	int		is_current;
	int		is_begin;
	int		namelen;
	char	*name;
};

t_arg		*to_first_arg(t_arg *node);
t_arg		*make_t_arg_lst(char **args);

void		init_window(int);
void		set_keypress(int status);

t_arg		*delete_t_arg(t_arg *arg);
void		print_arg(t_arg *arg);
void		print_all_args(t_arg *arg);
void		move_arg(t_arg **arg, char *direction);
int			t_arg_resize(t_arg *node);

void		ft_select_exit(int exit_param);
char		**read_directory(char *path);
void		return_value(t_arg *arg);

#endif
