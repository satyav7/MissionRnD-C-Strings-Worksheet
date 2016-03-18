/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int intPartReverse(float);
void number_to_str(float number, char *str, int afterdecimal){
	int i = 0, j, temp;
	if (number<0){
		str[i++] = '-';
		number *= -1;
	}
	int reverseInt = intPartReverse(number);
	while (reverseInt > 0){
		str[i] = reverseInt % 10 + '0';
		i++;
		reverseInt = reverseInt / 10;
	}
	if (afterdecimal>0){
		str[i++] = '.';
		for (j = 0; j<afterdecimal; j++){
			number *= 10;
			str[i++] = ((int)number % 10) + '0';
		}
	}
	str[i] = '\0';
}


int intPartReverse(float input){
	int reverseNumber = 0;
	while (input > 0.9){
		reverseNumber = (reverseNumber * 10) + ((int)input % 10);
		input = input / 10;
	}
	return reverseNumber;
}