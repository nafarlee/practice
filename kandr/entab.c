#include <stdio.h>

/* Write a program entab that replaces strings of blanks by the minimum number
 * of tabs and blanks to achieve the same spacing. Use the same tab stops as
 * for detab. When either a tab or a single blank would suffice to reach a tab
 * stop, which should be given preference? */

#define TABSTOP_LENGTH 8
#define MAX_CHARACTERS 140

void layDownSpaces(void);
void printRuler(void);
void incrementSpacer(void);
void updateTabstop(void);

int charUntilTabstop = TABSTOP_LENGTH;
int blankSpaces = 0;
int tabSpaces = 0;
int isCharReplaceQueued = 1;
int i = 0;
int c;
char input[MAX_CHARACTERS] = {"_"};

int main() {
	printRuler();

	while ( (c = getchar()) != EOF) {
		if (c == '\n') {
			blankSpaces = 0;
			tabSpaces = 0;
			isCharReplaceQueued = 1;
			charUntilTabstop = TABSTOP_LENGTH;
			input[i] = c;
			i++;
		}
		else if (c != ' ') {
			if(isCharReplaceQueued == 0) {
				isCharReplaceQueued = 1;	
				layDownSpaces();
			}
			updateTabstop();
			input[i] = c;
			i++;
		}
		else {
			isCharReplaceQueued = 0;
			incrementSpacer();
		}
	}

	if(isCharReplaceQueued == 0) {
		isCharReplaceQueued = 1;	
		layDownSpaces();
	}
	
	printf("\n%s\n", input);
	return 0;
}

void incrementSpacer(void) {
	blankSpaces++;
	if (blankSpaces == charUntilTabstop) {
		blankSpaces = 0;
		charUntilTabstop = TABSTOP_LENGTH;
		tabSpaces++;
	}
}

void updateTabstop(void) {
	charUntilTabstop--;
	if (charUntilTabstop == 0) {
		charUntilTabstop = TABSTOP_LENGTH;
	}
}

void layDownSpaces(void) {
	charUntilTabstop = charUntilTabstop - blankSpaces;
	while (tabSpaces > 0) {
		input[i] = '\t';
		i++;
		tabSpaces--;
	}
	while (blankSpaces > 0) {
		input[i] = ' ';
		i++;
		blankSpaces--;
	}
}

void printRuler(void) {
	int i, j;
	for (j = 0; j < 7; j++) {
		for (i = 0; i < (TABSTOP_LENGTH - 1); i++) {
			printf("_");
		}
		printf("|");
	}
	printf("\n");
}
