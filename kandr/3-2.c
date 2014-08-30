#include <stdio.h>
#include <string.h>

/* Write a fucntion escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters. */

enum ESCAPE  {TAB = '\t', NEWLINE = '\n'};

void escape(char source[], char target[]);
void unescape(char source[], char target[]);

int main(void) {
	char s[] = "The \n balls \t \t \t \t  are totally\n ready\t for\n my dick";
	char t[500] = {' '};
	char b[500] = {' '};
	escape(s, t);
	unescape(t, b);
	printf("\n%s\n", s);
	printf("\n%s\n", t);
	printf("\n%s\n", b);
	return 0;
}

void escape(char s[], char t[]) {
	int i, j;
	i = j = 0;

	while (s[i] != '\0') {
		switch(s[i]) {
			case TAB:
				t[j++] = '\\';
				t[j] = 't';
				break;
			case NEWLINE:
				t[j++] = '\\';
				t[j] = 'n';
				break;
			default:
				t[j] = s[i];
				break;
		}
		s++;
		j++;
	}
	t[j] = '\0';
}

void unescape(char s[], char t[]) {
	int i, j;
	i = j = 0;
	while (s[i] != '\0') {
		if (s[i] == '\\') {
			switch(s[i+1]) {
				case 't':
					t[j] = TAB;
					i++;
					break;
				case 'n':
					t[j] = NEWLINE;
					i++;
					break;
				default:
					t[j] = '\\';
					break;
			}
		}
		else {
			t[j] = s[i];
		}
		i++;
		j++;
	}
	t[j] = '\0';
}
