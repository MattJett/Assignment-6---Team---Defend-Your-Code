#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "myUtils.h"


int main () {
	char firstName[51];
	char lastName[51];
	long num1;
	long num2;
	char inputName[56];
	char outputName[56];
	
	getFname(firstName, (sizeof(firstName) - 1));
	getLname(lastName, (sizeof(firstName) - 1));

	num1 = getNum1();
	num2 = getNum2();

	getInputFile(inputName, (sizeof(inputName) - 1));
	getOutputFile(outputName, inputName, (sizeof(outputName) - 1));	

	getPassword();
	//https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/

	
	printf("\n\n Results: ");
	printf("\nFirst Name: %s", firstName);	
	printf("\nLast Name: %s", lastName);	
	printf("\nInt 1: %ld", num1);	
	printf("\nInt 2: %ld", num2);	
	printf("\nInput File Name: %s", inputName);	
	printf("\nOutput File Name: %s", outputName);	

	return 0;

}
