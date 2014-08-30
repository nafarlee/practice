#include <stdio.h>

#define LOWER 0
#define UPPER 100
#define STEP 5


main() {
	int cels; 
	printf("%3s %6s\n", "C", "F");

	for (cels = LOWER; cels <= UPPER; cels = cels +STEP){
		printf("%3d %6.1f\n", cels, (cels * 1.8) + 32);
	}
}
