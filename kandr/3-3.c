#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Write a function expain(s1, s2) that expands shorthand notations like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits, and be prepared to handle cases like
 * a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally. */

enum boolean {FALSE, TRUE};

void expand(char s[], char t[]);

int main(void) {
	char source[] = "a-g-t3-7T-Z";
	char target[500];
	expand(source, target);
	printf("%s\n", target);
	return 0;
}

void expand(char s[], char t[]) {
	int i, j;
	i = j = 0;
	char begin, end;

	while (s[i] != '\0') {
		if ( (isalnum(s[i])) && (isalnum(s[i+2])) && (s[i+1] == '-') ) {
			begin = s[i];
			end = s[i+2];
			while (begin < end ) {
				t[j++] = begin;
				begin++;
			}
			i++;
		}
		else {
			t[j++] = s[i];
		}
		i++;
	}
	t[j] = '\0';
}
