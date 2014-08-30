#include <stdio.h>

main() {
	int blanks, tabs, newlines;
	blanks = tabs = newlines = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			blanks++;
		if (c == '\t')
			tabs++;
		if (c == '\n')
			newlines++;
	}
	printf("Blanks: %d Tabs: %d Newlines: %d\n", blanks, tabs, newlines);
}
