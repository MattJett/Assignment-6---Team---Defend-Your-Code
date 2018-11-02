#include "myUtils.h"

void strip(char * array) {
	if(array == NULL) {
			perror("array is null");
			exit(-99);
	}// end if

	int len = strlen(array), x = 0;
   
	while(array[x] != '\0' && x < len){
	  if(array[x] == '\r')
		 array[x] = '\0';
	  else if(array[x] == '\n')
		 array[x] = '\0';
	  x++;

	}// end while
   
}// end strip


//User Inputs
// TODO: change from dummy to input
// dummy is 5, expect string 1-3. last character is for \n. 2nd to last character is to test if its over 3.
// 1234 => last character is \n, then its just 1234 and 2nd to last shows 4 is extra digit so it fails.
void getFname(char * fname, size_t len){
	int valid = -1;
	char input[52];
	char dummy[5];
	
	while(valid == -1) {
		printf("Enter First name (Between 1 to 50 characters. ONLY accepting letters)\n");
		printf("First Name: ");
		fgets(dummy, (sizeof(dummy)), stdin);
		cleanBuffers(dummy);
		//printf("test fname size: %d %s\n", (int)strlen(dummy), dummy);
		if(isValidName(dummy) == 0)
			valid = 0; // to test, change this to -1
		else
			printf("Your name input is invalid please try again! \n");	
	}
   strncpy(fname, input, len);	
}

// TODO: change from dummy to input
// also do we need to flush stdin?
void getLname(char * lname, size_t len){
    int valid = -1;
	char input[52];
	char dummy[5];
	
	while(valid == -1) {
		printf("Enter Last name (Up to 50 characters. ONLY accepting letters)\n");
		printf("Last Name: ");
		fgets(dummy, (sizeof(dummy)), stdin);
		cleanBuffers(dummy);
		//printf("test fname size: %d %s\n", (int)strlen(dummy), dummy);
		if(isValidName(dummy) == 0)
			valid = 0;
		else
			printf("Your name input is invalid please try again!\n");	
	}
}

// TODO: change dummy to input
// TODO: 000000000000000000001 should just convert to 1??? at this point sake of time, dont really care too much unelss
//		wants to tackkel it.

// wants 3 digits. +1 to check minus sign. +1 for \n. +1 for both minus and \n
//	hard to conceptualize but test it around it maeks sense 
long getNum1() {
	int valid = -1;
	long num = 0;
	char input[15];
	char dummy[6];
	
	while(valid == -1) {
		printf("\nEnter First Integer (Only digits between -2147483648 to 2147483647)\n");
		printf("Num1: ");
		fgets(dummy, (sizeof(dummy)), stdin);
		cleanBuffers(dummy);
		//printf("test num size: %d %s\n", (int)strlen(dummy), dummy);
		if(isValidNum(dummy) == 0)
			valid = 0; // to test, change this to -1
		else
			printf("Your name input is invalid please try again! \n");	
	}
	return num;
}

long getNum2() {
    int valid = -1;
	long num = 0;
	char input[15];
	char dummy[6];
	
	while(valid == -1) {
		printf("Enter Second Integer (Only digits between -2147483648 to 2147483647)\n");
		printf("Num2: ");
		fgets(dummy, (sizeof(dummy)), stdin);
		cleanBuffers(dummy);
		//printf("test num size: %d %s\n", (int)strlen(dummy), dummy);
		if(isValidNum(dummy) == 0)
			valid = 0; // to test, change this to -1
		else
			printf("Your name input is invalid please try again! \n");	
	}
	return num;
}

// TODO: change dummy to input
void getInputFile(char * inputName, size_t len) {
	int valid = -1;
	char input[52];
	char dummy[8];

	while(valid == -1) {
		printf("Enter name of text Input file in this directory (Up to 50 characters. Accepting ONLY .txt files AND ONLY letters and numbers)\n");
		printf("Input File: ");
		fgets(dummy, (sizeof(dummy)), stdin);
		cleanBuffers(dummy);
		printf("test inputname size: %d %s\n", (int)strlen(dummy), dummy);
		if(isValidFileName(dummy) == 0)
			valid = 0;
		else
			printf("Your file name input is invalid please try again!\n");
	}
}

void getOutputFile(char * outputName, size_t len) {
	int valid = -1;
	char input[52];
	char dummy[8];

	while(valid == -1) {
		printf("Enter name of text Output file in this directory (Up to 50 characters. Accepting ONLY .txt files AND ONLY letters and numbers)\n");
		printf("Output File: ");
		fgets(dummy, (sizeof(dummy)), stdin);
		cleanBuffers(dummy);
		printf("test inputname size: %d %s\n", (int)strlen(dummy), dummy);
		if(isValidFileName(dummy) == 0)
			valid = 0;
		else
			printf("Your file name input is invalid please try again!\n");
	}
}

void getPassword() {
	int valid = -1;
	char password[13];
	char passwordReEnter[13];
	unsigned char salt[SHA256_BLOCK_SIZE/2];
	unsigned char hash[SHA256_BLOCK_SIZE];

	while(valid == -1) {
		printf("Enter password (All letters, numbers, and some special characters are allowed, must be between 6-12 characters in length)\n");
		printf("Password: ");
		fgets(password, (sizeof(password)), stdin);
		cleanBuffers(password);
		//printf("test fname size: %d %s\n", (int)strlen(input), input);
		if(isValidPassword(password) == 0)
			valid = 0;
		else
			printf("Your contained either too many or too few characters, or an invalid character!\n");
	}

	// generate salt
	SHA256_CTX ctx;
	sha256_init(&ctx);
	// append salt char[] to password[] make new password
	// hash new password
	// write salt and hashedpassword to account.txt file
}


// Validation
// TODO: change range to 1-50
int isValidName(char * name) {
	strip(name);
    size_t size = strlen(name);
	//printf("test validname size: %d\n", size);
	if(regex(name,"^[a-zA-Z]{1,3}$") == 0)
		return 0;
	return 1;
}

int isValidNum(char * num) {
    strip(num);
	size_t size = strlen(num);
	//printf("test number size: %d %s\n", size, num);
	if(regex(num,"^[\\-]?([0-9]{1,3})$") == 0)
		return 0;
	return 1;
}

// TODO: change range to 1-54
int isValidFileName(char * fileName) {
	strip(fileName);
	size_t size = strlen(fileName);
	//printf("test validname size: %d\n", size);
	if(regex(fileName, "^[a-zA-Z0-9]{1,3}.txt$") == 0)
		return 0;
	return 1;
}

int isValidPassword(char * password) {
    
}

// Modified by using https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples
int regex(char * input, char * pattern) {
	regex_t regex;
	regcomp(&regex, pattern, REG_EXTENDED);
	return regexec(&regex, input, 0, NULL, 0);
}

// gets rid of the rest of stdin if stdin gets too long
void cleanBuffers(char *buf)
{
    if(!strchr(buf, '\n'))
        while(fgetc(stdin) != '\n')/*Discard*/;
    else
        strtok(buf, "\n");
}



