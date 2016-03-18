/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char[], int, int);
void str_words_in_rev(char *input, int len){
	int i, start = 0, end;
	reverse(input, 0, len - 1);
	for (i = 0; i<len; i++){
		if (input[i] == ' ' || i == len - 1){
			if (i == len - 1)
				end = i;
			else
				end = i - 1;
			reverse(input, start, end);
			start = i + 1;
		}

	}
}

void reverse(char *input, int start, int end){
	int temp, i, mid;
	mid = (start + end) / 2;
	for (i = start; i <= end; i++){
		temp = input[i];
		input[i] = input[end];
		input[end] = temp;
		mid--;
		end--;
	}

}