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
# define KEY_SELECT			115
# define KEY_UNSELECT		117

/*
**			t_arg (aka struct s_arg):
**
**			col, row - coordinates at the output
** 			type: 0 - usual file or smth else, 1 - directory, 2 - binary, 3 - symlink
**			is_selected - flag of the
*/

typedef struct s_arg t_arg;

struct s_arg
{
	t_arg	*prev;
	t_arg	*next;

	int 	col;
	int 	row;
	int		type;
	int 	is_selected;
	int 	is_current;
	int 	namelen;
	char 	*name;
};

t_arg		*make_t_arg_lst(char **args, char *cur_dir);
void		print_arg(t_arg *arg);
void		move_next(t_arg **arg);
void		move_prev(t_arg **arg);
void		ft_select_exit(void);






#endif