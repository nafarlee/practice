#include <stdio.h>
#include <ctype.h>

/* Rewrite the function lower, which converts upper case letters to lower
 * case, with a conditional expression instead of if-else */

char lower(char character);

int main(void) {
	char input[] = "I AlwAYs WaKE UP ANd yoU GuyS ArE TALKiNg abOUT DEAth";
	int i;
	for (i = 0; input[i] != '\0'; i++) {
		input[i] = lower(input[i]);
	}
	printf("%s\n", input);
	return 0;
}

char lower(char c) {
	return ((isupper(c)) ? (c + 32) : (c));
}
