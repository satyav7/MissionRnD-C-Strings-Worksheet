/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int getString(char *str1, char *str2);
void buildStr(char *src, char *dest);
int getWordCount(char *str);
char ** commonWords(char *str1, char *str2) {
	if (str1 == 0 || str2 == 0)
		return NULL;
	else
	{
		int wordsCount = 0, str1Counter = 0, str3Counter = 0;
		int str1WordCount = getWordCount(str1);

		char **str1SingleWord = (char **)malloc(str1WordCount*sizeof(char *));
		char **commonWords = (char **)malloc(str1WordCount*sizeof(char *));

		for (wordsCount = 0; wordsCount < str1WordCount; wordsCount++){
			str1SingleWord[wordsCount] = (char *)malloc(SIZE*sizeof(char));
			commonWords[wordsCount] = (char *)malloc(SIZE*sizeof(char));
			commonWords[wordsCount][0] = '\0';
		}

		for (wordsCount = 0, str1Counter = 0; str1[wordsCount] != '\0'&&str1Counter<str1WordCount; wordsCount++){
			if (str1[wordsCount] != ' '){
				str1SingleWord[str1Counter][str3Counter++] = str1[wordsCount];
			}
			else if (str1[wordsCount] == ' ')
			{
				str1SingleWord[str1Counter][str3Counter] = '\0';
				str1Counter++;
				str3Counter = 0;
			}
		}
		str1SingleWord[str1Counter][str3Counter] = '\0';


		for (wordsCount = 0, str1Counter = 0; wordsCount < str1WordCount; wordsCount++){
			if (getString(str2, str1SingleWord[wordsCount]) == 1){
				buildStr(str1SingleWord[wordsCount], commonWords[str1Counter]);
				str1Counter++;
			}
		}

		if (str1Counter>0)
			return commonWords;
		else
		{
			return NULL;
		}
	}
}



void buildStr(char *str, char *finalStr){

	int i = 0;

	while (str[i] != '\0')
		finalStr[i] = str[i++];

	finalStr[i] = '\0';
}

int getWordCount(char *str){

	int i = 0, count = 1;

	while (str[i] != '\0'){

		if (str[i] == ' ')
			count++;

		i++;
	}

	return count;

}

int getString(char *str1, char *str2){
	int str1Counter = 0, str2Counter = 0;
	while (str1[str1Counter] != '\0'){
		while (str1[str1Counter] == str2[str2Counter] && str2[str2Counter] != '\0'){
			str1Counter++;
			str2Counter++;
		}
		if (str2[str2Counter] != '\0'&&str2Counter>0){
			str2Counter = 0;
		}
		str1Counter++;
	}
	if (str2Counter > 0)
		return 1;
	return 0;
}