#include <stdio.h>
#include <string.h>

/* Write a recursive version of the function reverse(s), which reverses the
 * string s in place. */

#define MAXVAL 100

void reverse(char string[]);
void swap(char s[], int i);

int main(void) {
	char s[] = "shits";
	printf("Your input: %s\n", s);
	reverse(s);
	printf("Reversed: %s\n", s);
	return 0;
}

void reverse(char s[]) {
	static int i = 0;
	swap(s, i);
	i++;
	if ((i*2) < strlen(s)) {
		reverse(s);
	}
	else {
		s[i*2] = '\0';
	}
}

void swap(char s[], int i) {
	int temp;

	temp = s[strlen(s)-i-1];
	s[strlen(s)-i-1] = s[i];
	s[i] = temp;
}

