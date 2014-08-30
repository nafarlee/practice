#include <stdio.h>

#define FALSE 1
#define TRUE 0

main() {

	int c;
	int inword = FALSE;
	
	while ( (c = getchar()) != EOF) {
		if (c == ' ' && inword == TRUE) {
			inword = FALSE;
			printf("\n");
		}
		if (c != ' ' && inword == FALSE) {
			inword = TRUE;
		}
		if (c != ' ') {
			putchar(c);
		}
	}
}
