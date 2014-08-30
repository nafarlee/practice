#include <stdio.h>

#define is_odd(x) (x % 2)

int get_collatz_length(unsigned long long);

int main(void) {
	const int LIMIT = 1000000;

	int record = 0;
	int winner = 0;

	int i;
	for (i = 2; i < LIMIT; i++) {
		int length = get_collatz_length(i);
		if (length > record) {
			winner = i;
			record = length;
		}
	}

	printf("The winner is %i with an all time high of %i\n", winner, record);
	return 0;
}

int get_collatz_length(unsigned long long number) {
	int length = 0;
	while (number != 1) {
		if (is_odd(number)) {
			length += 2;
			number = (3 * number + 1) / 2;
		}
		else {
			length++;
			number /= 2;
		}
	}

	return length + 1;
}

