#include <stdio.h>

#define MAX 999

void getTrimmedInput(char string[]);

int main() {
	
	char input[MAX] = {};

	getTrimmedInput(input);
	printf("\nYour output:\n%s", input);
	
	return 0;
}

void getTrimmedInput(char string[]) {

	int c;
	int i = 0;
	int trimmed = 1;

	string[0] = '\0';
	while ((c = getchar()) != EOF) {
		if (c  == '\n' && string[i-1] == '\n')
			;
		else {
			string[i] = c;
			i++;
		}
	}

	int end = i - 1;

	int head;
	head = i = 0;
	while (head <  end) {
		while ((string[i] != '\n') && (string[i] != EOF)) {
			i++;
		}

		head = i + 1;
		i--;
		while ((string[i] == ' ') || (string[i] == '\t') || (string[i] == '\n')) {
			string[i] = '_';
			i--;		
		}
		i = head;

		printf("%s\n", string);
		printf("%d %d  \n", head, end);
	}

}
