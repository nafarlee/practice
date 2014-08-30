#include <stdio.h>
#include <string.h>

char* number_to_english(int);
int character_count(char[]);

int main(void) {
	int i;
	int sum = 0;

	for (i = 1; i <= 1000; i++) {
		sum += character_count(number_to_english(i));
	}

	printf("%i\n", sum);
	return 0;
}

int character_count(char string[]) {
	int char_count = 0;
	int i = 0;
	while (string[i] != '\0') {
		if (string[i] != ' ' && string[i] != '\0') {
			char_count++;
		}
		i++;
	}
	return char_count;
}

char* number_to_english(int number) {
	static const char *names[] = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eighteen",
		"nineteen",
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety",
	};

	static char string[100];

	if (number <= 20) {
		strcpy(string, names[number]);
	}
	else if (number < 100) {
		int leading = number / 10;
		int lowend = number % 10;
		strcpy(string, names[leading+18]);

		if (lowend != 0) {
			strcat(string, " ");
			strcat(string, names[lowend]);
		}
	}
	else if (number < 1000) {
		int leading = number / 100;
		int loworder = number % 100;
		int middle = (number % 100) / 10;
		int lowend = number % 10;

		strcpy(string, names[leading]);
		strcat(string, " hundred");

		if (loworder > 0) {
			strcat(string, " and ");
			if (loworder <= 20) {
				strcat(string, names[loworder]);
			}
			else {
				strcat(string, names[middle+18]);
				if (lowend != 0) {
					strcat(string, " ");
					strcat(string, names[lowend]);
				}
			}
		}


	}
	else {
		strcpy(string, "one thousand");
	}
	return string;
}
