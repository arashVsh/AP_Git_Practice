#include<stdio.h>
int main()
{
	int a;
	char *x;
	x = (char *)&a;
	a = 512;
	x[0] = 1;
	printf("%d\n", a);
	return 0;
}
/*
x[]  adad 'a' ra be soorat hex zakhire mikonad
x[0] -> a % 256  ra zakhire mikonad
x[1] -> a / 256

ta khat 7 : x[0] =0 , x[1] =2
8 : x[0]=1 , x[1]=2
a= 256*2 + 1 =513
print 513

*/