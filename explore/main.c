# include <stdlib.h>
# include <termcap.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>
# include <ftw.h>


# include <unistd.h>
# include <sys/param.h>

static struct termios kuku;


void	key()	
{
	struct termios s;
	tcgetattr(STDERR_FILENO, &kuku);
	s = kuku;
	s.c_lflag &= ~(ICANON | ECHO);
	s.c_cc[VMIN] = 1;
	s.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &s);
}

int main()
{
	int	c;
	printf("kuku\n");
	while (1)
	{
		c = getc(stdin);
		key();
		printf("%d\n", c);
	}
	return (0);
}
