#include <stdio.h>

main() {

	int c;
	int cc[127] = {0};
	int length = sizeof(cc) / sizeof(cc[0]);

	while ( (c = getchar()) != EOF) {
		cc[c]++;
	}

	printf("\n");
	int i;
	for (i = 0; i < length; i++) {
		if (cc[i] != 0) {
			printf("%c: ", i);
			int j;
			for (j = 0; j < cc[i]; j++) {
				printf("|");
			}
			printf("\n");
		}
	}

	printf("\n");
}

