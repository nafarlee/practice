#include <stdio.h>

unsigned getbits(unsigned number, int position, int places);

int main(void) {
	printf("%u\n", getbits(22, 3, 4));
	
	return 0;
}

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p+1-n)) & ~(~0 << n);
}
