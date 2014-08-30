#include <stdio.h>

/* Write a program to "fold" long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column. */

#define COLUMN_LIMIT 80
#define MAX_INPUT 140

void printRuler(void);

int c;
char input[MAX_INPUT];	
int i = 0;
int column = 1;

int main() {
	printRuler();
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			input[i] = '\n';
			i++;
			column = 1;
		}
		else if (c != ' ') {
			if (column <= COLUMN_LIMIT) {
				input[i] = c;
				i++;
				column++;
			}
			else {
				int j = i;
				while (input[j] != ' ') {
					j--;
				}
				input[j] = '\n';
				input[i] = c;
				column = i - j;
				i++;
			}
		}
		else {
			if (column > COLUMN_LIMIT) {
				input[i] = '\n';
				i++;
				column = 1;
			}
			else {
				input[i] = c;
				i++;
				column++;
			}
		}
	}

	printf("\n%s\n", input);
	return 0;
}

void printRuler(void) {
	int i = 1;
	while (i < COLUMN_LIMIT) {
		printf("_");
		i++;
	}
	printf("|\n");
}
