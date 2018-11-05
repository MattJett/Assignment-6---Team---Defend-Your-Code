#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "myUtils.h"

/*
gcc (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


*/

int main () {
	char firstName[51];
	char lastName[51];
	long num1;
	long num2;
	char inputFileName[56];
	char outputFileName[56];

	FILE * error = fopen("error.txt", "w");
	fprintf(error, "ERROR LOG\n");
	fclose(error);

	getFname(firstName, (sizeof(firstName) - 1));
	getLname(lastName, (sizeof(firstName) - 1));

	num1 = getNum1();
	num2 = getNum2();

	getInputFile(inputFileName, sizeof(inputFileName)-1);
	getOutputFile(outputFileName, inputFileName, sizeof(outputFileName)-1);

	getPassword();
	//Modified from https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/

	printToFile(inputFileName, outputFileName, lastName, firstName, num1, num2);
	//Modified from https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/

	//printf("\n\n Results: ");
	//printf("\nFirst Name: %s", firstName);	
	//printf("\nLast Name: %s", lastName);	
	//printf("\nInt 1: %ld", num1);	
	//printf("\nInt 2: %ld", num2);	
	//printf("\nInput File Name: %s", inputFileName);	
	//printf("\nOutput File Name: %s", outputFileName);	

	return 0;
}
