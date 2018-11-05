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
	char inputFileName[56];
	char outputFileName[56];
	FILE * inputFile;
	FILE * outputFile;
	
	getFname(firstName, (sizeof(firstName) - 1));
	getLname(lastName, (sizeof(firstName) - 1));

	num1 = getNum1();
	num2 = getNum2();

	getInputFile(inputFile, inputFileName);
	getOutputFile(outputFile, outputFileName, inputFileName);

	getPassword();
	//Modified from https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/

	printToFile(outputFile, inputFile, lastName, firstName, num1, num2);
	//Modified from https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/

	printf("\n\n Results: ");
	printf("\nFirst Name: %s", firstName);	
	printf("\nLast Name: %s", lastName);	
	printf("\nInt 1: %ld", num1);	
	printf("\nInt 2: %ld", num2);	
	printf("\nInput File Name: %s", inputFileName);	
	printf("\nOutput File Name: %s", outputFileName);	

	return 0;
}
