#include <stdio.h>
#include <string.h>
#include <limits.h>

/* Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16)
 * formats n as a hexadecimal integer in s. */

void itob(int number, char string[], int base);
int highbase(int number, int base);

int main(void) {
	char s[50];
	itob(32, s, 2);
	printf("%s\n", s);
	printf("%i\n", 16*256);

	return 0;
}

void itob(int n, char s[], int b) {
	int i, sign;
	unsigned int k = n;
	sign = n;
	int high = highbase(n, b);
	i = 0;

	while ((high >  1)) {
		s[i++] = ((k / high) > 9) ? ((k / high) - 10 + 'A') : ((k / high) + '0');  
		k %= high;
		high /= b;
	}
	s[i++] = (k > 9) ? k  - 10 + 'A' : (k + '0'); 

	if (sign < 0) {
		s[i++] = '-';
	}

	s[i] = '\0';
}

int highbase(int n, int b) {
	int high = b;
	while ((high *= b) <= n)
		;
	return high / b;
}
