#include <stdio.h>
#include <string.h>
#include <limits.h>

/* In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2^(wordsize-1). Explain why not. Modify it to print that value correctly,
 *  regardless of the machine on which it runs. */

void itoa(int number, char string[]);
void reverse(char string[]);

int main(void) {
	char s[50];
	itoa(INT_MIN, s);
	printf("%s\n", s);
	printf("%i\n", INT_MIN);

	return 0;
}

void itoa(int n, char s[]) {
	int i, sign;
	unsigned int k = n;
	sign = n;




	i = 0;
	do {
		s[i++] = k % 10 + '0';
	} while ((k /= 10) > 0);

	if (sign < 0) {
		s[i++] = '-';
	}

	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
