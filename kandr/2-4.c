#include <stdio.h>
#include <string.h>

/* Write an alternate version of squeeze(s1, s2) that deletes each character
 * in s1 that matches any character in the string s2. */

void squeeze(char s1[], char s2[]);
void shiftrm(char string[], int position);

int main(void) {
	char string[] = "the quick brown fox jumps over the lazy dog";
	char squeezer[] = "aeiou";
	squeeze(string, squeezer);
	printf("%s\n", string);
	return 0;
}

void squeeze(char s1[], char s2[]) {
	int i, j;
	for (i = 0; i < strlen(s1); i++) {
		for (j = 0; j < strlen(s2); j++) {
			if (s1[i] == s2[j]) {
				shiftrm(s1, i);
				i--;
				break;
			}
		}
	}
}

void shiftrm(char string[], int position) {
	while (string[position - 1] != '\0') {
		string[position++] = string[position+1];
	}
}
