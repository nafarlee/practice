#include <stdio.h>

/* Define a macro swap(t,x,y) that interchanges two arguments type t. (Block
 * structure will help) */

#define swap(t,x,y) t = x;\
					x = y;\
					y = t

int main(void) {
	int a, b, c;
	a = 5;
	b = 3;
	printf("a is equal to: %d\n", a);
	printf("b is equal to: %d\n", b);
	swap(c, a, b);
	printf("a is equal to: %d\n", a);
	printf("b is equal to: %d\n", b);
	return 0;
}
