#include <stdio.h>

#define TRUE  0
#define FALSE  1

main() {

	int c;
	int inblanks = FALSE;

	while( (c = getchar()) != EOF) {
		if ( c != ' ' ){
			inblanks = FALSE;
			putchar(c);
		}
		else {
			if (inblanks == TRUE)
				;
			else {
				inblanks = TRUE;
				putchar(c);
			}

		}
	}
}
