#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int *p = arr;
	++*p;
	p += 2;
	printf("%d", *p);
	return 0;
}

// no problems are present syntaxially and the program runs correctly not sure of the logics
// Here is the output: 3