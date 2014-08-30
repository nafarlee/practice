#include <stdio.h>

/* Write a function htoi(s) which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The
 * allowable digits are 0 through 9, a through f, and A through F. */

enum boolean { FALSE, TRUE };

int htoi(char string[]);
int strlen(char string[]);
int square(int root, int power);
int hexConv(char hex);
int isHex(char c);

int main(void) {
	char string[] = "0xhf83io50";

	printf("The hexadecimal sequence %s in decimal is equal to %d\n",string,  htoi(string));
	return 0;
}

int htoi(char string[]) {
	int total = 0;
	int power = 0;
	int i;
	int decValue = 0;
	int temp = 0;

	for (i = strlen(string); (i >= 0) && (string[i]!='x') && (string[i]!='X'); i--) {
		if ((isHex(string[i]) == TRUE)) {
			decValue = hexConv(string[i]);
			printf("%d\n", decValue);
			temp = (decValue * square(16, power));
			power++;
			total += temp;
		}
	}
	return total;
}

int strlen(char string[]) {
	int i = 0;
	while (string[i] != '\0') {
		i++;
	}
	return i-1;
}

int square(int root, int power) {
	if (power == 0) {
		return 1;
	}
	if (power == 1) {
		return root;
	}

	int total = root;
	while (power > 1) {
		total = total * root;
		power--;
	}
	return total;
}

int hexConv(char hex) {
	if ((hex == 'F') || (hex == 'f')) {
		return 15;
	}
	else if (hex == 'E' || hex == 'e') {
		return 14;
	}
	else if (hex == 'D' || hex == 'd') {
		return 13;
	}
	else if (hex == 'C' || hex == 'c') {
		return 12;
	}
	else if (hex == 'B' || hex == 'b') {
		return 11;
	}
	else if (hex == 'A' || hex == 'a') {
		return 10;
	}
	else {
		int temp = hex - '0';
		return temp;
	}
}

int isHex(char c) {
	char hex[] = "0123456789abcdefABCDEF";
	int i;
	int contains = FALSE;
	for (i = 0; (i < strlen(hex)) && (contains == FALSE); i++) {
		if (hex[i] == c) {
			contains = TRUE;
		}
	}
	return contains;
}
