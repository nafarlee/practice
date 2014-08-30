#include <stdio.h>

/* for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 * 	s[i] = c;
 * Write a loop equivalent to the for loop above without using && or || */

#define MAX_INPUT 10

enum boolean { FALSE, TRUE };


int main(void) {
	int stop = FALSE;
	int i = 0;
	int lim = MAX_INPUT;
	char s[MAX_INPUT] = {' '};
	int c;


	while (stop == FALSE) {
		c = getchar();
		if (i > (lim-1)) {
			stop = TRUE;
		}
		else if (c == '\n') {
			stop = TRUE;
		}
		else if (c == EOF) {
			stop = TRUE;
		}
		else {
			s[i] = c;
			i++;
		}
	}
	printf("%s\n", s);

	return 0;
}
