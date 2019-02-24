#include <stdlib.h>
#include <stdio.h>
#include <termcap.h>
#include <termios.h>
#include <string.h>
#include <term.h>




void		reset_keypress(void)
{
	tcsetattr(0,TCSANOW,&stored_settings);
}

int			main(void)
{


	while(1)
	{


	}
	return 0;
}