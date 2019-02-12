//program that sorts words given by user
//author: fmoham26 (Fawaz Mohammad)
//compiled and tested on obelix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20 //maximum amount of chars allowed in a word
#define MAX_WORDS 50 //maximum words to sort


void custom_sort(char **allWords, int wordCount);



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


	custom_sort(allWords,wordCount); //calls sort functioon on unsorted list

	//prints the sorted list
	for(i = 0; i < wordCount; i++){
		printf("%s\n", allWords[i]);
	}


	

	return 0;

}

//sorts words given a list of words and the number of words to sort
void custom_sort(char **allWords, int wordCount){

	int cmp; //integer which keeps track if a word is "greater", "less than", or "equal" to another word
	char tmp[21]; //21 because of end string character
	int i,j;

	//iterates and switches the place of a word
	//with a word ahead of it if the first word is greater than the second word
	//by doing this at every index, we will end up with a sorted list
	for(i = 0; i < wordCount; i++){

		for(j = i + 1; j < wordCount; j++){

			cmp = strcmp(allWords[i], allWords[j]); //compares strings

			if (cmp > 0){ //switches location of words if there are in the wrong position
				strcpy(tmp, allWords[i]);
				strcpy(allWords[i], allWords[j]);
				strcpy(allWords[j], tmp);
				


			}

			

		}


	}

}
