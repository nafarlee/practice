#include <stdio.h>

/* Write a program to check a C program for rudimentary syntax errors like
 * unbalanced parentheses, brackets, and braces. Don't forget about quotes, 
 * both single and double, escape sequences, and comments. (This program is 
 * hard if you do it in full generality.) */

#define MAX_SIZE 6000

void syntaxCounter(int i);
void getInput(void);
void errorCheck(void);

static char input[MAX_SIZE];
static short parens = 0, brackets = 0, braces = 0;

int main() {
	getInput();

	int i = 0;
	while (input[i] != '\0') {

		if (input[i] == '\"') {
			i++;
			while (input[i] != '\"') {
				i++;
			}
			i++;
		}
		else if ((input[i] == '/') && (input[i+1] == '*')) {
			i += 2;
			while ((input[i] == '*') && (input[i+1] == '/')) {
				i++;
			}
			i++;
		}
		else if ((input[i] == '/') && (input[i+1] == '/')) {
			while (input[i] != '\n') {
				i++;
			}
			i++;
		}
		else {
			syntaxCounter(i);
			i++;
		}
	}

	printf("\n\nBrackets:%d\nBraces:%d\nParentheses:%d\n", brackets, braces, 
			parens);
	errorCheck();
	return 0;
}

void syntaxCounter(int i) {
	char c = input[i];
	if ((c == ')') || (c == '(')) {
		parens++;
	}
	if ((c == '[') || (c == ']')) {
		braces++;
	}
	if ((c == '{') || (c == '}')) {
		brackets++;
	}
}

void getInput(void) {
	int c;
	short i = 0;
	while ((c = getchar()) != EOF) {
		input[i] = c;
		i++;
	}
}

void errorCheck(void) {
	if ((brackets % 2) != 0) {
		printf("%s\n", "Missing Bracket");
	}
	if ((parens % 2) != 0) {
		printf("%s\n", "Missing Parens");
	}
	if ((braces % 2) != 0) {
		printf("%s\n", "Missing Braces");
	}
}
