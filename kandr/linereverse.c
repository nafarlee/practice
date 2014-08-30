#include <stdio.h>

#define ARRAYSIZE 140


void reverse(char source[], char target[]);

int main() {
	char forward[ARRAYSIZE] = {' '};
	char backward[ARRAYSIZE] = {' '};
	int i;
	int c;

	while ( c != EOF ) {
		i = 0;
		while ((c = getchar()) != '\n') {
			if (c == EOF) {
				break;
			}
			forward[i] = c;
			i++;
		}
		if (c != EOF){
			reverse(forward, backward);

			printf("%s\n", backward);
		}
	}

	return 0;

}

void reverse(char source[], char target[]) {
	int si = 0;
	int ti = 0;

	while (source[si] != '\0') {
		si++;
	}

	si--;
	
	while (si >= 0) {
		target[ti] = source[si];
		si--;
		ti++;
	}
}
