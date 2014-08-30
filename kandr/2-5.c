#include <stdio.h>
#include <string.h>

/* Write the function any(s1,s2), which returns the first location in the
 * string s1 where any character from the string s2 occurs, or -1 if s1
 * contains no characters from s2. (The standard library function strpbrk does
 * the same job but returns a pointer to the location.) */

int any(char s1[], char s2[]);

int main(void)
{
	char string[] = "Look at them they're so in love I bet they'll french kiss"
		"all night long I wish we knew which hole he's gonna poke her through";
	char pool[] = "g";
	printf( "%d\n", (any(string, pool)) );
	return 0;
}

int any(char s1[], char s2[]) {
	int i, j, found;
	found  = 0;
	for (i = 0; (i < strlen(s1)) && (found == 0); i++) {
		for (j = 0; j < strlen(s2); j++) {
			if (s1[i] == s2[j]) {
				found = 1;
				break;
			}
		}
	}
	if (found != 0) {
		return i;
	}
	else {
		return -1;
	}
}
