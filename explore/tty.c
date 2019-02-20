#include <unistd.h>
#include <stdio.h>

int 		main(void)
{
	puts(ttyname(0));
	puts(ttyname(1));
	puts(ttyname(2));
	printf("%d\n", ttyslot());
}