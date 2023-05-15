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
/*
5: *p = arr[0] =>1
6: *p => 2  --> arr[]{2,2,3,4,5}
7: *p = arr[2] =>3
print: 3

*/