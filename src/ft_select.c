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


	printf("%s%s", clstr, test1);
}

extern char		**environ;

int				main(int ac, char **av, char **en)
{
	char	c;
	init_window();
	while (1)
	{
		set_keypress();
		printf(" ");
		c = getc(stdin);
		if (c == 10)
		{
			// printf("%s\n", cursor_right);
		}
	}
	exit(0);
}