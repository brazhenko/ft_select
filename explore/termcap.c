#include <stdlib.h>
#include <stdio.h>

#include <termios.h>
#include <string.h>

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

	while(1)
	{
		set_keypress();
		printf("Test:        ");
		// putchar здесь вызывается для того, чтобы проверить работоспособность
		c = getc(stdin);
		printf("%d\n", c);
		printf("\n");

	}
	return 0;
}