#include <stdio.h>

#define FALSE 1
#define TRUE 0

main() {

	int c;
	int word = 0;
	int inword = FALSE;

	while ( (c = getchar()) != EOF) {
		if ( (c != ' ' && c != '\t' && c != '\n') && inword == FALSE) {
			word++;
			inword = TRUE;
		}
		if (c == ' ' || c == '\t' || c == '\n') {
			inword = FALSE;
		}
	}

	printf("Number of words: %d\n", word);
}
