/*
 * ---------------------------------
 * Student Name: marissa angeles
 * Student ID:200377290
 * Student Email:
 * ---------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Lab6.h"

char* encrypt(char *plaintext, int key) {


	key = key % 26;

	char *ciphertext = malloc(strlen(plaintext)+1);

	int upper = False;
	int i = 0;
	char plainletter, cipherletter;

	plainletter = plaintext[i];
	while (plainletter != '\0'){

		if ( isalpha(plainletter) ){

			if (isupper(plainletter) )
				upper = True;
			plainletter = tolower(plainletter);
			cipherletter = (plainletter + key);

			if (cipherletter >'z'){
				cipherletter -= 26;
			}
			if (upper){
				cipherletter = toupper(cipherletter);
			}

		}
		else{
			cipherletter = plainletter;
		}
		ciphertext[i] = cipherletter;
		i++;
		upper = False;
		plainletter = plaintext[i];
	}
	ciphertext[i] = '\0';

	return ciphertext;
}


char* decrypt(char *ciphertext, int key) {

	key = key % 26;

		char *plaintext = malloc(strlen(ciphertext)+1);

		int upper = False;
		int i = 0;
		char plainletter, cipherletter;

		cipherletter = ciphertext[i];
		while (cipherletter != '\0'){

			if ( isalpha(cipherletter) ){

				if (isupper(cipherletter) )
					upper = True;
				cipherletter = tolower(cipherletter);
				plainletter = (cipherletter) -key;

				if (plainletter <'a'){
					plainletter += 26;
				}
				if (upper){
					plainletter = toupper(plainletter);
				}

			}
			else{
				plainletter = cipherletter;
			}
			plaintext[i] = plainletter;
			i++;
			upper = False;
			cipherletter = ciphertext[i];
		}
		plaintext[i] = '\0';

		return plaintext;
}
