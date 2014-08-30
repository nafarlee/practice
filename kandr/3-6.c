#include <stdio.h>
#include <string.h>

/* Write a version of itoa that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough. */

void itoa(int number, char string[], int min);
void reverse(char string[]);

int main(void) {
	char s[50];
	itoa(56, s, 40);
	printf("%s\n", s);

	return 0;
}

void itoa(int n, char s[], int min) {
	int i, sign;
	sign = n;
	if (n < 0) {
		n = -n;
	}
	unsigned int k = n;

	i = 0;
	do {
		s[i++] = k % 10 + '0';
		min--;
	} while (((k /= 10) > 0));
	if (sign < 0) {
		s[i++] = '-';
		min--;
	}
	while (min > 0) {
		s[i++] = ' ';
		min--;
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
