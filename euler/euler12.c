#include <stdio.h>

#define length(x) (sizeof(x) / sizeof(0[x]))

typedef unsigned long triangle;

int get_amount_factors(triangle);
void print_array(triangle[], int);
void triangle_fill(triangle[], int);

int main(void) {
	const int ARRAY_SIZE = 100000;
	triangle array[ARRAY_SIZE];

	triangle_fill(array, length(array));

	int i;
	for (i = 0; i < length(array); i++) {
		triangle current_num = array[i];
		int factor_amount = get_amount_factors(current_num);
		if (factor_amount > 500) {
			printf("Number: %lu, Factors: %i\n", current_num, factor_amount);
			break;
		}
	}
	return 0;
}

void triangle_fill(triangle array[], int length) {
	array[0] = 1;

	int index;
	for (index = 1; index < length; index++) {
		triangle prev_number = array[index-1];
		array[index] = prev_number + index + 1;
	}
}

void print_array(triangle array[], int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("%lu\n", array[i]);
	}
}

int get_amount_factors(triangle number) {
	int factor_amount = 0;
	int i;
	for (i = 1; i <= number/2; i++) {
		factor_amount = (number % i == 0) ? factor_amount+1 : factor_amount;
	}
	return factor_amount + 1;
}
