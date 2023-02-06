#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rothelper.h"
#include "vigenere.h"

char rotate(char in, int howmuch){

	if(howmuch < 0){
		howmuch += 26;
	}
	howmuch = howmuch %26;
	int bound;
	int new_in;

	if (!(in >= 'a' && in <= 'z' || in >= 'A' && in <= 'Z')){
		return in;
	}
	if (in >= 'a' && in <= 'z'){
		bound = in + howmuch;
		if ( bound > 'z'){
			new_in = (in - 26) + howmuch;
			return new_in;
		}
	}
	if (in >= 'A' && in <= 'Z'){
		bound = (in + howmuch);
		if(bound > 'Z'){
			new_in = (in - 26) + howmuch;
			return new_in;
		}
	}
	else{
		new_in = in + howmuch;
		return new_in;
	}
}

char* flattenKey(char* key) {

	int len = stringlength(key);
	char* flattenedKey = malloc(len + 1);
	int j = 0;

	for (int i = 0; i < len; i++){
		if (isalpha(key[i])) {
			flattenedKey[j++] = key[i];
		}
	}

	flattenedKey[j] = '\0';

	return flattenedKey;

}

int viggyhelper(char key[]){
	int howmuch = 0;
	if (key[0] >= 'A' && key[0] <= 'Z'){
		howmuch = key[0] - 'A';
	}
	else if (key[0] >= 'a' && key[0] <= 'z'){
		howmuch = key[0] - 'a';
	}
	return howmuch;
}

char* encipher(char somewords[], char key[]){
	char* flattenedKey = flattenKey(key);
	int letterCount = stringlength(somewords);
	int keyCount = stringlength(flattenedKey);
	char* message = (char*) malloc(sizeof(char) * (letterCount + 1));

	for(int i = 0; i < letterCount; i++){
		message[i] = rotate(somewords[i], viggyhelper(flattenedKey + i % keyCount));
	}

	message[letterCount] = '\0';
	free(flattenedKey);
	return message;

}

char* decipher(char somewords[], char key[]){
	char* flattenedKey = flattenKey(key);
	int letterCount = stringlength(somewords);
	int keyCount = stringlength(flattenedKey);
	char* message = (char*) malloc(sizeof(char) * (letterCount + 1));

	for(int i = 0; i < letterCount; i++){
		message[i] = rotate(somewords[i], -viggyhelper(flattenedKey + i % keyCount));
	}

	message[letterCount] = '\0';
	free(flattenedKey);
	return message;

}
