#include <stdio.h>

#define ARRAYSIZE 140


void reverse(char source[], char target[]);

int main() {
	char forward[ARRAYSIZE] = "Do you get pinned and smothered on the ground by Goliath-sized grapplers, unable to move and unable";
	char backward[ARRAYSIZE] = {' '};

	reverse(forward, backward);

	printf("%s\n", forward);
	printf("%s\n", backward);

	return 0;

}

void reverse(char source[], char target[]) {
	int si = 0;
	int ti = 0;

	while (source[si] != '\0') {
		si++;
		printf("%d\n", si);
	}

	si--;
	
	while (si >= 0) {
		printf("%d %d \n", si, ti);
		target[ti] = source[si];
		si--;
		ti++;
	}
}
