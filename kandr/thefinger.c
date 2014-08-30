#include <stdio.h>

/* Define a macro swap(t,x,y) that interchanges two arguments type t. (Block
 * structure will help) */

void thefinger(void);

int main(void) {
	printf("What is your name?\n");
	char s[50];
	int i = 0;
	int c;
	while ((c = getchar()) != '\n') { s[i++] = c; }
	s[i] = '\0';
	printf("Well fuck you %s\n", s);
	thefinger();
	return 0;
}

void thefinger(void) {
	printf("....................../´¯/)\n"
		"....................,/¯../ \n"
		".................../..../ \n"
		"............./´¯/'...'/´¯¯`·¸\n"
		"........../'/.../..../......./¨¯\\ \n"
		"........('(...´...´.... ¯~/'...') \n"
		".........\\.................'...../ \n"
		"..........''...\\.......... _.·´ \n"
		"............\\..............( \n"
		"..............\\.............\\...");
}
