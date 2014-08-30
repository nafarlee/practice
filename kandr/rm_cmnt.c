#include <stdio.h>

/* Write a program to remove all comments from a C program. Don't forget to
 * handle quoted strings and character constants properly. C commendts do not
 * nest */

#define MAX_INPUT 99999


int c;
char input[MAX_INPUT] = {" "};
int i = 0;
int in_cmnt = 1;
int in_qte = 1;
int in_star = 1;
int prevc = 0;

int main() {
	while ((c = getchar()) != EOF) {
		if (in_qte == 0) {
			input[i] = c;
			if (input[i] == '\"') {
				in_qte = 1;
			}
			i++;
		}
		else {
			if (in_star == 1) {
				if (in_cmnt == 1) {
					if (c == '\"') {
						input[i] = c;
						i++;
						in_qte = 0;
					}
					else if ((c == '*') && (input[i-1] == '/')) {
						input[i - 1] = ' ';
						in_star = 0;
					}
					else if ((c == '/') && (input[i - 1] == '/')) {
						input[i - 1] = ' ';
						in_cmnt = 0;
					}
					else {
						input[i] = c;
						i++;
					}
				}
				else {
					if (c == '\n') {
						input[i] = '\n';
						i++;
						in_cmnt = 1;
					}
				}
			}
			else {
				if ((c == '/') && (prevc == '*')) {
					in_star = 1;
				}
				else {
					prevc = c;
				}
			}
		}
	}

	printf("\nYour Input:\n%s\n", input);
	return 0;
}
