
/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count_letters(const char *filename, int counters[26]);
void write_results(const char *filename, int counters[26]);
void append_sum(const char *filename, int counters[26]);

int main() {
	setbuf(stdout, NULL);

	char filename[20] = "text1.txt";
	int counters[26] = { 0 };

	count_letters(filename, counters);

	filename[4] = '2';
	write_results(filename, counters);

	append_sum(filename, counters);

	printf("Check text2.txt for output\n");

	return 0;
}

void count_letters(const char *filename, int counters[26]) {
	//your code here
	FILE = *a;
	a = fopen(filename, "r");

	//error handling
	if (filename == NULL) {
		printf("Error(count_letters): Could not open file text1.txt");
		return;
	}

	char c;

	while((fgets(&c,1, a)) != NULL) {
		if (isalpha(c)) {
		islower(c);
		int position = (c - 'a');
		counters[position]++;

		}
	}
	return;
}

void write_results(const char *filename, int counters[26]) {
	//your code here
	FILE = *a;
	a = fopen("text2.txt", "w");

	//error handling
		if (filename == NULL) {
			printf("Error(write_results): Could not open file text1.txt");
			return;

	//print to text2
		int i = 0, counter_size = 26;
		char[] = "abcdefghijklmnopqrstuvwxyz";

		for (i = 0; i < counter_size; i++){
			fprintf(a, "count(%s)", char[i]);
			fprintf(a, " = %d", counters[i]);

			}
		}

	return;

}

void append_sum(const char *filename, int counters[26]) {
	//your code here
		FILE = *a;
		a = fopen("text2.txt", "w");

	//error handling
		if (filename == NULL) {
			printf("Error(append_sum): Could not open file text1.txt");
			return;
		}

		int i = 0, counter_size = 26, sum = 0;
		for (i = 0; i < counter_size; i++){
			sum += counters[i];
		}
		fprintf(a, "Total = %d", sum);
	return;
}

