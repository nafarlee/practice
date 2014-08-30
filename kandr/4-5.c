#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Add commands to print the top element of the stack without popping, to
 * duplicate it, and to swap the top two elements. Add a command to clear the
 * stack. */ 

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void dupe(void);
void swap(void);
void shatter(void);

int main(void) {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				  push(pop() + pop());
				  break;
			case '*':
				  push(pop() * pop());
				  break;
			case '-':
				   op2 = pop();
				   push(pop() - op2);
				   break;
			case '/':
				   op2 = pop();
				   if (op2 != 0.0) {
				   	push(pop() / op2);
				   }
				   else {
				   	printf("error:zero divisor\n");
				   }
				   break;
			case '\n':
				   printf("\t%.8g\n", pop());
				   break;
			case '%':
				   op2 = pop();
				   push(fmod(pop(), op2));
				   break;
			case 'S':
				  push(sin(pop()));
				  break;
			case 'E':
				  push(exp(pop()));
				  break;
			case 'P':
				  op2 = pop();
				  push(pow(pop(), op2));
				  break;
			default:
				   printf("error: unknown command %s \n", s);
				   break;
		}
	}

	return 0;
}


#define MAXVAL 	100

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	}
	else {
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void) {
	if (sp > 0) {
		return val[--sp];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

double peek(void) {
	double temp = pop();
	push(temp);
	return temp;
}

void dupe(void) {
	push(peek());
}

void swap(void) {
	double temp = pop();
	double temp2 = pop();
	push(temp);
	push(temp2);
}

void shatter(void) {
	sp = 0;
}


#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
	int i, c, sign;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') { 
		if (c == '-') {
			c = getch();
			if (isdigit(c)) {
				s[0] = '-';
				ungetch(c);
			}
			else {
				ungetch(c);
				return '-';
			}
		}
		else {
			return c;
		}
	}
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch())) 
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;	
}


#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
