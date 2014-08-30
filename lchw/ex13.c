#include <stdio.h>

#define to_lower(c) (c >= 65 && c <= 90) ? (c + 32) : c

int main (int argc, char *argv[]) {
	if (argc != 2) {
		printf("ERROR: You need one argument.\n");
		// this is how you abort a program
		return 1;
	}

	int i = 0;
	for (i = 0; argv[1][i] != '\0'; i++) {
		char letter = to_lower(argv[1][i]);
		switch (letter) {
			case 'a':
				printf("%d 'a'\n", i);
				break;

			case 'e':
				printf("%d 'e'\n", i);
				break;

			case 'i':
				printf("%d 'i'\n", i);
				break;

			case 'o':
				printf("%d 'o'\n", i);
				break;

			case 'u':
				printf("%d 'u'\n", i);
				break;

			case 'y':
				if (i > 2) {
					// it's only sometimes Y
					printf("%d 'y'\n", i);
				}
				break;

			default:
				printf("%d: %c is not a vowel\n", i, letter);
		}
	}

	return 0;
}
