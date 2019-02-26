#include <stdio.h>

int		f()
{
	return (1);
}

int (*getFunc(int a, int b))(void)
{
	return (f);	
}


int				main(void)
{
	printf("%d\n", getFunc(1, 2)());
}
