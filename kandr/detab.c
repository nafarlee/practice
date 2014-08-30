#include <stdio.h>

#define TABSTOP 8
#define MAXSIZE 999

/* Write a program detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops,
 * say every n columns. Should n be a variable or a symbolic parameter? */

void printRuler(void);

int main() {
	char input[MAXSIZE] = {' '};
	int c;
	int i = 0;
	int tabcount = TABSTOP;

	printRuler();

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			tabcount = TABSTOP;
			input[i] = c;
			i++;
		}
		else if (c == '\t') {
			int spaceamount = tabcount;
			tabcount = TABSTOP;
			while (spaceamount > 0) {
				input[i] = '_';
				spaceamount--;
				i++;
			}
		}
		else {
			if (tabcount > 1) {
				tabcount--;
			}
			else {
				tabcount = TABSTOP;
			}
			input[i] = c;
			i++;
		}
	}

	printf("\n\n%s\n", input);
	return 0;
}

void printRuler(void) {
	int i, j;
	for (j = 0; j < 7; j++) {
		for (i = 0; i < (TABSTOP - 1); i++) {
			printf("_");
		}
		printf("|");
	}
	printf("\n");
}
