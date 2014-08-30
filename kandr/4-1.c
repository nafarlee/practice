#include <stdio.h>
#include <string.h>

/* Write the function strrindex(s,t), which returns the position of the
 * rightmost occurence of t in is, or -1 if there is none. */

enum boolean {FALSE, TRUE};

int strrindex(char source[], char target[]);
int wordcheck(char source[], int sindex, char target[]);

int main(void) {
	char t[] = "me";
	char s[] = "Time for the man in the mirror to die";

	printf("-1 means the sequence was not found\n");
	printf("The sequence '%s' was found at position %i\n", t, strrindex(s,t));
	return 0;
}

int strrindex(char s[], char t[]) {
	int si, ti;
	si = strlen(s) - strlen(t);
	ti = 0;

	while (si > 0) {
		while (s[si] != t[0]) {
			si--;
			if (si < 0) {
				return -1;
			}
		}
		if (wordcheck(s, si, t)) {
			return si;
		}
		else {
			si--;
		}
	}
	return -1;	
}

int wordcheck(char s[], int si, char t[]) {
	int ti;

	for (ti = 0; ti < strlen(t); ti++, si++) {
		if (s[si] != t[ti]) {
			return FALSE;
		}
	}
	return TRUE;
}
