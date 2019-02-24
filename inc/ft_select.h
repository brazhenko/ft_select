#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <term.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>

/*
**			t_arg (aka struct s_arg):
**
** 			type: 0 - usual file or smth else, 1 - directory, 2 - binary, 3 - symlink
**
**
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
	int 	namelen;
	char 	*name;
};

t_arg		*make_t_arg_lst(char **args);


#endif