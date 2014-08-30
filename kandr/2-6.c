#include <stdio.h>

/* Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged. */

unsigned setbits(unsigned target, int position, int places, unsigned modifier);

int main(void)
{
	unsigned result = 0;
	result = setbits(156, 5, 5, 178);
	printf("%u\n", result);
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	y = y & ~(~0 << n);
	y = y << (p+1-n);
	x = x & ~( (~(~0 << n)) << (p+1-n) );
	x = x | y;
	return x;
}
