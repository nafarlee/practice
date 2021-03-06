#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* Write a routine ungets(s) that will push back an entire string onto the
 * input. Should ungets know about buf and bufp, or should it just use
 * ungetch */ 

#define MAXOP 100
#define NUMBER '0'
#define VARIABLE '#'

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void dupe(void);
void swap(void);
void shatter(void);
void ungets(char s[]);

int main(void) {
	int type;
	double op2;
	char s[MAXOP];
	double recent = 0;
	double var[26] = {0};
	double temp = 0;

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				temp = atof(s);
				push(temp);
				break;
			case VARIABLE:
				temp = s[0] - '0';
				push(temp);
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
				   recent = pop();
				   printf("\t%.8g\n", recent);
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
			case '$':
				  op2 = pop();
				  var[(int)(op2-49)] = peek();
				  break;
			case '@':
				  temp = pop();
				  push(var[(int)temp - 49]);
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
	if (islower(c)) {
		s[0] = c;
		s[1] = '\0';
		return VARIABLE;
	}
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


#define BUFSIZE 1

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

void ungets(char s[]) {
	int i;
	for (i = 0; i < strlen(s); i++) {
		ungetch(s[i]);
	}
}
