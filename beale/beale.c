#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rothelper.h"
#include "beale.h"

char* first_letters(char filename[]){

        FILE* fp = fopen(filename, "r");

        if(fp == NULL){
                printf("Error opening file \n");
                return NULL;
        }

        char buf[255];
        int c = fscanf(fp, "%s", buf);
	int i = 0;
	int count = count_words(filename);
        char* array = malloc(count * sizeof(char));
        while (c != EOF){
                array[i] = buf[0];
                c = fscanf(fp, "%s", buf);
		i++;
        }
        fclose(fp);

        return array;
}

int* encipher(char* str, Beale b){

        int arrlength = strlen(str);
        int* message = malloc((arrlength + 1) * sizeof(int));

        for(int i = 0; i < arrlength; i++){
                message[i] = -1;
                if(str[i] == ' '){
                        message[i] = -1;
                }else{
                        for(int j = 0; j < b.length; j++){
                                if(str[i] == b.letters[j]){
                                        message[i] = j;
                                        break;
                                }
                        }
                }
        }

        message[arrlength] = -2;
        return message;
}

char* decipher(int* msg, Beale b){

        int len = 0;
        while (msg[len] != -2) {
            len++;
        }

        char* message = malloc((len + 1) * sizeof(char));

        for(int i = 0; i < len; i++){
                if(msg[i] == -1){
                        message[i] = '*';
                        continue;
                }else{
                        for(int j = 0; j < b.length; j++){
                                if(msg[i] == j){
                                        message[i] = b.letters[j];
                                        break;
                                }
                        }
                }
        }
        message[len] = '\0';
        return message;
}

Beale create_cipher(char filename[]) {
        int count = count_words(filename);
        char* array = first_letters(filename);
        Beale b = {count, array};
        return b;
}

int count_words(char filename[]){

        FILE* fp = fopen(filename, "r");

        if(fp == NULL){
                printf("Error opening file \n");
                return 0;
        }

        char buf[255];
        int totalWords = 0;
        int c = fscanf(fp, "%s", buf);

        while (c != EOF){
                totalWords += 1;
                c = fscanf(fp, "%s", buf);
        }
        fclose(fp);
        return totalWords;
}
