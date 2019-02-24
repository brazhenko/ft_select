#include "ft_select.h"



void term_caps()
{
	char *clstr;
	char *cmstr;
	int cs;
	char *tmp;
	int line;
	clstr=tgetstr("cl",0); /* очистка экрана */
	cmstr=tgetstr("cm", 0); /* перемещение y,x */
	line=tgetnum("li"); /* полосы терминала */
	cs=tgetnum("co"); /* колонки терминала */
	tmp=tgetstr("pc",0); /* символ дозаполнения */
	PC=tmp ? *tmp : 0;
	BC=tgetstr("uc",0); /* сдвиг курсора на символ влево */
	UP=tgetstr("up",0); /* сдвиг курсора на линию вверх */

}

void		set_keypress(void)
{
	static struct termios stored_settings;

	struct termios new_settings;

	tcgetattr(0,&stored_settings);

	new_settings = stored_settings;

	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;

	tcsetattr(0,TCSANOW,&new_settings);
}

void	init_window(void)
{

	char buf[1024];
	char *termtype=getenv("TERM");
	int ok=tgetent(buf,termtype);
	char *test1=tgetstr("cl",0); /* очистка экрана */

	char *clstr=tgetstr("ti",0); /* запуск терминала */
	char *test2=tgetstr("vi",0); /*  */
	char *test3 = tgetstr("nd", 0);


	printf("%s%s%s\n", clstr, test1, test2);
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
	lst = make_t_arg_lst(av + 1, cur_dir);
	init_window();
	while (--ac)
	{
		print_arg(lst);
		lst = lst->next;
	}
	while (1)
	{
		set_keypress();
		read(STDIN_FILENO, &key, 8);
		if (key == KEY_ESC)
			ft_select_exit();
		if (key == KEY_DOWN)
			move_arg(&lst, "next");
		if (key == KEY_UP)
			move_arg(&lst, "prev");
		else if (key == KEY_SPC)
		{
			lst->is_selected = ~lst->is_selected;
			print_arg(lst);
		}
		else if (key == 1111111)
			exit(0);
		key = 0;
	}
	exit(0);
}