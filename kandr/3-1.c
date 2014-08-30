#include <stdio.h>

/* Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time. */

int binsearch(int value, int array[], int lastposition);

int main(void) {
	int v[] = {1, 3, 7, 9, 12, 15, 18, 24, 25, 28, 29, 34, 35};
	printf("%i\n", binsearch(18, v, 13));
	return 0;
}

int binsearch(int x, int v[], int n) {
	int low, high, mid, save;
	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		}
		else {
			save = mid;
			low = mid + 1;
		}
	}

	if (v[save] == x) {
		return save;
	}
	else {
		return -1;
	}
}
