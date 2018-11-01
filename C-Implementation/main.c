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
	char inputName[51];
	char outputName[51];
	
	getFname(firstName, (sizeof(firstName) - 1));
	getLname(lastName, (sizeof(firstName) - 1));

	num1 = getNum1();
	num2 = getNum2();
	
	return 0;

}
