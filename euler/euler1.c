#include <stdio.h>

#define multiple_3_or_5(x) (x % 3 == 0 || x % 5 == 0)

int main(void) {
	const int LIMIT = 1000;

	unsigned long sum = 0;
	int i;
	for (i = 0; i < LIMIT; i++) {
		sum = multiple_3_or_5(i) ? sum+i : sum;
	}

	printf("%lu\n", sum);
	return 0;
}
