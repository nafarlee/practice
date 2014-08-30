#include <stdio.h>

/* In a two's complement number system, x &= (x-1) deletes the rigthmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of 
 * bitcount */

int bitcount(unsigned number);

int main(void) {
	printf("%u\n", bitcount(11));
	return 0;
}

int bitcount(unsigned x) {
	int count = 0;
	while (x > 0) {
		x &= (x-1);
		count++;
	}
	return count;
}
