#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number my be followed by e or E and an optionally
 * signed exponenet */

double atof(char s[]);

int main(void) {
	printf("\n%f\n\n", atof("123.12e-3"));
	return 0;
}

double atof(char s[]) {
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1: 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
	}
	else {
		return (sign * val) / power;
	}

	double eval;
	int esign;
	esign = (s[i] == '-') ? -1: 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (eval = 0.0; isdigit(s[i]); i++) {
		eval = 10.0 * eval + (s[i] - '0');
	}
	
	return (sign * val / power) * (pow(10, esign*eval));
}

