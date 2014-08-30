#include <stdio.h>

/* Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
 * others unchanged. */

unsigned invert(unsigned target, int position, int places);

int main(void) {
	printf("%u\n", invert(1490, 8, 5));
	return 0;
}

unsigned invert(unsigned x, int p, int n) {
	unsigned temp = (~0);
	temp = temp << n;
	temp = ~temp;
	temp = temp << (p+1-n);
	return (x ^ temp);
}
