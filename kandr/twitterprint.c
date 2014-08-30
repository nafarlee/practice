#include <stdio.h>

#define MAXLINE 1000
#define QUOTA 80


int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int length;
	char line[MAXLINE];

	while ((length = getLine(line, MAXLINE)) > 0) {
		if (length > QUOTA) {
			printf("\nFulfilled %d character quota: %s", QUOTA,  line);
			
		}
	}
	return 0;
}

int getLine(char s[], int lim) {
	int c, i;

	for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i ) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
