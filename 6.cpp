#include<stdio.h>
int main()
{
	char a;
	char* x;
	x = &a;
	a = 512;
	x[0] = 1;
	printf("%d\n", a);
	return 0;
}
