#include<stdio.h>
int main()
{
	int a;
	char* x;
	x = (char*)&a;
	a = 512;
	x[0] = 1;
	printf("%d\n", a);
	return 0;
}
//no problems are present syntaxially no sure about the logics of the program!
//Here is the output: 513