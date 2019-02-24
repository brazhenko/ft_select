#include <stdlib.h>
#include <stdio.h>

#include <string.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <time.h>
# include <curses.h>
# define CM (tgetstr("cm", NULL))

static struct termios stored_settings;

void		set_keypress(void)
{
	struct termios new_settings;

	tcgetattr(0,&stored_settings);

	new_settings = stored_settings;

	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;

	tcsetattr(0,TCSANOW,&new_settings);
}

void		reset_keypress(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);
}

int			main(void)
{
	char c;
	char buf[1024];
	char buf2[30];
	char *ap = buf2;
	char *clearstr, *gotostr, *standstr, *stendstr;

	tgetent(buf, getenv("TERM"));

	clearstr = tgetstr("cl", &ap);
	gotostr = tgetstr("cm", &ap);
	standstr = tgetstr("so", &ap);
	stendstr = tgetstr("se", &ap);
	int x, y;

	x = 5; y = 3;
	while(1)
	{
		set_keypress();
		// putchar здесь вызывается для того, чтобы проверить работоспособность
		if (c == 27)
		{
			fputs(tgoto(gotostr, x+10, y), stdout);
			fputs(standstr, stdout);
			printf("Hello2");
			fputs(stendstr, stdout);
			fputs(tgoto(gotostr, x, y), stdout);
			printf("Hello");
		}
		if (c == 10)
		{
			fputs(tgoto(gotostr, x, y), stdout);
			fputs(standstr, stdout);
			printf("Hello");
			fputs(stendstr, stdout);
			fputs(tgoto(gotostr, x + 10, y), stdout);
			printf("Hello2");
		}
		c = getc(stdin);
		//printf("%d\n", c);
		//printf("\n");

	}
	return 0;
}