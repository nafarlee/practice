#include <stdio.h>

unsigned long long move(int, int, unsigned long long, int);

int main(void) {
	const int BIGGEST_CUBE = 20;
	
	unsigned long long routes = 6;
	int grid;
	for (grid = 3; grid <= BIGGEST_CUBE; grid++) {
		routes = move(0, 0, routes, grid);
		printf("A grid of size %i has %llu routes.\n", grid, routes);
	}
	return 0;
}

unsigned long long move(int x, int y, unsigned long long prev_paths, int grid) {
	int prev_grid = grid-1;
	if ((grid - x == prev_grid) && (grid - y == prev_grid)) {
		return prev_paths;
	}

	if (x < grid && y < grid) {
		return move(x+1, y, prev_paths, grid) + move(x, y+1, prev_paths, grid);
	}
	else if (x < grid && y == grid) {
		return move(x+1, y, prev_paths, grid);
	}
	else if (x == grid && y < grid) {
		return move(x, y+1, prev_paths, grid);
	}
	else {
		return 1;
	}
}
