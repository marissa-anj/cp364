/*
 -------------------------------------
 File:    Lab5.c
 Project: Lab5
 file description
 -------------------------------------
 Author:  Nick Liu
 ID:      180713700
 Email:   liux3700@mylaurier.ca
 Version  2022-06-06
 -------------------------------------
 Author:  Marissa Angeles
 ID:      200377290
 Email:   ange7290@mylaurier.ca
 Version  2022-06-06
 -------------------------------------
 */

//place your include statements here
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stdbool.h>
# define STRING_MAX 30

char* format_string(char *in_str);
void test_format_string();

int main() {
	setbuf(stdout, NULL);
	test_format_string();
	return 0;
}

//1- strip any white space from the end of the string
//2- capitalize first character of every word, all others lower case
//3- replace white spaces with _
//4- Enclose between []
//5- remove any digit characters
char* format_string(char *in_str) {
	//your solution here
	char *s = malloc(strlen(in_str));

	strcpy(s, in_str);

	int size = strlen(s) - 1, i;

	while (size > 0) {
		if (isspace(s[size])) {
			size--;
		} else {
			break;
		}

	}
	s[size + 1] = '\0';

	for (i = 0; s[i] != '\0'; i++) { //convert all characters in string to lower case
		s[i] = tolower(s[i]);
	}

	for (i = 0; s[i] != '\0'; i++) {
		if (i == 0) { //if the character is the first character in the string
			if (isalpha(s[i])) {
				s[i] = toupper(s[i]);
			}

		}
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') { //if the letter before is a space, tab or new line
			++i;
			s[i] = toupper(s[i]);
		}
	}

	for (i = 0; s[i] != '\0'; i++) { //replacing space with underscore
		if (isspace(s[i]) || s[i] == '\t' || s[i] == '\n') {
			s[i] = '_';
		}
	}

	int j;

	for (i = 0; i < strlen(s); i++) {		//removing digits
		while (!(isalpha(s[i]))) {
			for (j = i; s[j]!= '\0'; j++) {
				s[j] = s[j + 1];
			}
			s[j] = '\0';
		}
	}

	for (i = (int)strlen(s); i >= 0; i--) { //adding square brackets
		s[i + 1] = s[i];
	}
	s[0] = '[';
	s[strlen(s)] = ']';
	s[strlen(s) + 1] = '\0';

	return s;
}

void test_format_string() {
	printf("------------------------------\n");
	printf("Start: Testing format_string:\n\n");

	printf("Case 1:\n");
	char in_str[STRING_MAX];
	strcpy(in_str, "ontar0io ");
	printf("len(in_str)  = %d, in_str = %s\n", strlen(in_str), in_str);
	char *out_str = format_string(in_str);
	printf("len(out_str) = %d, out_str = %s\n", strlen(out_str), out_str);
	printf("\n");

	printf("Case 2:\n");
	strcpy(in_str, "7aLbErTa \n");
	printf("len(in_str)  = %d, in_str = %s\n", strlen(in_str), in_str);
	out_str = format_string(in_str);
	printf("len(out_str) = %d, out_str = %s\n", strlen(out_str), out_str);
	printf("\n");

	printf("Case 3:\n");
	strcpy(in_str, "");
	strcpy(in_str, "new yor23k \n\t ");
	printf("len(in_str)  = %d, in_str = %s\n", strlen(in_str), in_str);
	out_str = format_string(in_str);
	printf("len(out_str) = %d, out_str = %s\n", strlen(out_str), out_str);
	printf("\n");

	printf("Case 4:\n");
	strcpy(in_str, "");
	strcpy(in_str, "south OF waterloo\t");
	printf("len(in_str)  = %d, in_str = %s\n", strlen(in_str), in_str);
	out_str = format_string(in_str);
	printf("len(out_str) = %d, out_str = %s\n", strlen(out_str), out_str);
	printf("\n");

	printf("Case 5:\n");
	strcpy(in_str, "");
	strcpy(in_str, "eastern\tside\tof\tKitcheNer");
	printf("len(in_str)  = %d, in_str = %s\n", strlen(in_str), in_str);
	out_str = format_string(in_str);
	printf("len(out_str) = %d, out_str = %s\n", strlen(out_str), out_str);
	printf("\n");

	free(out_str);
	out_str = NULL;

	printf("End: Testing format_string\n");
	printf("------------------------------\n\n");
	return;
}


