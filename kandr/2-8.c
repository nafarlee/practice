#include <stdio.h>

/* Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n bit positions. */

int rightrot(unsigned target, int places);

int main(void) {
	printf("%u\n", rightrot(8,3));
	return 0;
}

int rightrot(unsigned x, int n) {
	unsigned temp;
	while (n > 0) {
		if (x%2 == 0) {
			temp = 0;
		}
		else {
			temp = ~0;
			temp = temp >> 1;
			temp = ~temp;
		}
		x = x >> 1;
		x = x | temp;
		n--;
	}
	return x;
}
