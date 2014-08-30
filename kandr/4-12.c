#include <stdio.h>
#include <string.h>

/* Adapt the ideas of itoa to write a recursive version of itoa; that is, 
 * convert an integer into a string by calling a recursive routine. */

#define MAXVAL 100

void itoa(int n, char s[]);

int main(void) {
	char shit[MAXVAL] = {' '};
	itoa(34329, shit);
	printf("Your integer as a string is: %s\n", shit);
	return 0;
}

void itoa(int n, char s[]) {
	static int i = 0;
	if (n < 0) {
		s[i++] = '-';
		n = -n;
	}
	if (n/10) {
		itoa(n/10, s);
	}
	else {
		s[i+1] = '\0';
	}
	s[i++] = (n % 10 + '0');
}
