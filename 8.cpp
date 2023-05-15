#include<stdio.h>
const char * f(const char **p) {
	auto q = (p + sizeof(char))[1];
	return q;
}
int main() {
	const char * str[] = { "Wish","You","Best",":D" };
	printf("%c%c ", *f(str), *(f(str) + 1));
	printf("%c%c%c%c\n", **str, *(*(str + 1) + 1), *((str + 2)[-1] + 1), **&*(&str[-1] + 1));

	
}
/*
8: *f(str) => Best --> B , *(f(str)+1) => e
9: **str => W , *(*(str+1)+1) => o , (str+2)[-1]--> You => o ,  W
Be WooW
*/