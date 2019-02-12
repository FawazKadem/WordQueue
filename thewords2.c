//program that sorts words given by user using qsort
//author: fmoham26 (Fawaz Mohammad)
//compiled and tested on obelix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20 //maximum amount of chars allowed in a word
#define MAX_WORDS 50 //maximum words to sort



int strcmp_fixcast(const void* a, const void* b);



int main(){

	char *allWords[MAX_WORDS]; //array storing all the words

	
	int wordCount = 0;
	int i;



	for(i = 0; i < MAX_WORDS; i++){
		allWords[i] = (char *) malloc(MAX_WORD_LENGTH);


		printf("Enter Word:		");

		fgets(allWords[i], 20, stdin); //gets input from user

		if (allWords[i][0] == '\n'){
			
			break; //breaks if input is just a newline
			
		}

		strtok(allWords[i], "\n"); //remove trailing new line
		wordCount++;



	}

	//calls q sort, fixing the casting on the strcmp function
	qsort(allWords, wordCount, sizeof(char*), strcmp_fixcast);

	//prints array
	for(i = 0; i < wordCount; i++){
		printf("%s\n", allWords[i]);
	}


	

	return 0;

}

//casts a string pointer onto str cmp arguments
int strcmp_fixcast(const void* a, const void* b) { 
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    return strcmp(aa, bb);
}

