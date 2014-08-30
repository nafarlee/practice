#include <stdio.h>

main() {

	int wordlength = 0;
	int wc[40] = {0};
	int c;
	int length = sizeof(wc) / sizeof(wc[0]);

	while ( (c = getchar()) != EOF) {
		if ( (c != ' ') && (c != '\n') && (c != '\t') ) {
			wordlength++;
		}
		else {
			if (wordlength != 0) {
				wc[wordlength] += 1;
				wordlength = 0;
			}
		}
	}

	printf("\n");

	int i;
	for (i = 0; i < length; i++) {
		if (wc[i] != 0) {
			printf("%d: ", i);
			int j;
			for (j = 0; j < wc[i]; j++) {
				printf("|");
			}
			printf("\n");
		}
	}

	printf("\n");
}
