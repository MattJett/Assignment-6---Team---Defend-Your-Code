#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "myUtils.h"

int main()
{
	char firstName[51];
	char lastName[51];
	long num1;
	long num2;
	char inputFileName[51];
	char outputFileName[51];

	getFname(firstName, (sizeof(firstName) - 1));
	getLname(lastName, (sizeof(firstName) - 1));

	num1 = getNum1(); // use num1 and num2 pointers as parameters for method?
	num2 = getNum2();

	getInputFile(inputFileName, sizeof(inputFileName) - 1);
	getOutputFile(outputFileName, inputFileName, sizeof(outputFileName) - 1);

	getPassword();

	return 0;
}
