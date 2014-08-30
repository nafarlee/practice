#include <stdio.h>
#include <stdbool.h>

#define length(x) (sizeof x / sizeof 0[x])

void erat_sieve(bool[], int);
unsigned long long erat_sum(bool[], int);
void init_erat_array(bool[], int);

int main(void) {
	const int HIGHEST_NUMBER = 2000000 + 1;
	bool primes[HIGHEST_NUMBER];

	init_erat_array(primes, length(primes));
	erat_sieve(primes, length(primes));

	printf("%llu\n", erat_sum(primes, length(primes)));
	return 0;
}

unsigned long long erat_sum(bool prime_list[], int length) {
	unsigned long long prime_sum = 0;
	int i;
	for (i = 0; i < length; i++) {
		if (prime_list[i] == true) {prime_sum += i;}
	}
	return prime_sum;
}

void init_erat_array(bool array[], int length) {
	if (length > 2) {
		array[0] = false;
		array[1] = false;

		int i;
		for (i = 2; i < length; i++) {
			array[i] = true;
		}
	}
}

void erat_sieve(bool prime_list[], int length) {
	if (length > 2) {
		int base = 2;
		int prime_index = base;
		while (base < length) {
			for (prime_index = 2*base; prime_index < length; prime_index += base) {
				prime_list[prime_index] = false;
			}
			
			base += 1;
			while (prime_list[base] == false) {
				base += 1;
			}
			prime_index = base;
		}
	}
}
