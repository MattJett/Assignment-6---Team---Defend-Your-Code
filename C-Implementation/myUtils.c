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
   strncpy(fname, dummy, len);	
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
   strncpy(lname, dummy, len);	
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
		if(isValidNum(dummy) == 0) {
			valid = 0; // to test, change this to -1
			num = atol(dummy);
		} else {
			printf("Your name input is invalid please try again! \n");	
		}
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
		if(isValidNum(dummy) == 0) {
			valid = 0; // to test, change this to -1
			num = atol(dummy);
		} else {
			printf("Your name input is invalid please try again! \n");	
		}
	}
	return num;
}

// TODO: change dummy to input
void getInputFile(char * inputName, size_t len) {
	int valid = -1;
	char input[56];
	char dummy[8];

	while(valid == -1) {
		printf("\nEnter name of text Input file in this directory (Up to 50 characters. Accepting ONLY .txt files AND ONLY letters and numbers)\n");
		printf("Input File: ");
		fgets(input, (sizeof(input)), stdin);
		cleanBuffers(input);
		//printf("test inputname size: %d %s\n", (int)strlen(input), input);
		if(isValidFileName(input) == 0)
			valid = 0;
		else
			printf("Your file name input is invalid please try again!\n");
	}
	strncpy(inputName, input, len);
}

void getOutputFile(char * outputName, char * inputName, size_t len) {
	int valid = -1;
	char input[56];
	char dummy[8];

	while(valid == -1) {
		printf("Enter name of text Output file thats not the same as input in this directory.\n (Up to 50 characters. Accepting ONLY .txt files AND ONLY letters and numbers)\n");
		printf("Output File: ");
		fgets(dummy, (sizeof(dummy)), stdin);
		cleanBuffers(dummy);
		//strip(dummy);
		//printf("test inputname size: %d %s\n", (int)strlen(dummy), dummy);
		if(isValidFileName(dummy) == 0 && strcmp(dummy, inputName) != 0)
			valid = 0;
		else
			printf("Your file name input is invalid please try again!\n");
	}
	strncpy(outputName, dummy, len);
}

void getPassword() {

	char password[12];
	char salt[12];
	int valid = -1;

	while(valid == -1) {
		printf("\nEnter a password (ONLY Letters and Numbers, Max size of 10)\n");
		printf("Password #1: ");
		fgets(password, sizeof(password), stdin);
		cleanBuffers(password);
		//printf("test password size: %d %s\n", (int)strlen(password), password);
		if(isValidPassword(password) == 0)
			valid = 0;
		else
			printf("Your password input is invalid please try again!\n");
	}
	
	FILE * file = fopen("password.txt", "w");

	//pwd, 			sizeof(pwd), 	fName, 			sizeof(fName), 	output)
	//char *pwd, 	int bufSize, 	char *salt, 	int saltSize, 	FILE *errFile)

	// Get Password 1, hashsalt -> combine password + hashsalt. then hash.
	unsigned char hash [SHA256_BLOCK_SIZE], saltHash [SHA256_BLOCK_SIZE];
	
	hashPwd (salt, sizeof(salt), saltHash);
	char saltedPwd [sizeof(password) + sizeof(saltHash)];
	strncpy (saltedPwd, password, sizeof(password));
	strncat (saltedPwd, (char *)saltHash, sizeof(saltHash));
	hashPwd (saltedPwd, sizeof(password), hash);

	fwrite (hash, sizeof(hash[0]), (sizeof(hash)/sizeof(hash[0])), file);
	fclose (file);

	// get password 2. hashsalt, combine password + hashalt, then hash. compare from original password
	// that was written to file. compares. end if the same, else it'll reprompt to input password again.
	// password two will accept any.
	file = fopen("password.txt", "r");
	unsigned char hash2 [SHA256_BLOCK_SIZE], passwordOneHash [SHA256_BLOCK_SIZE], saltHash2 [SHA256_BLOCK_SIZE];

	int ch = fgetc(file), ind = 0;
	while(ch != EOF) {
		passwordOneHash[ind++] = (unsigned char) ch;
		ch = fgetc(file);
	}

	valid = -1;
	while (valid == -1) {
		printf("Enter the second password (ONLY Letters and Numbers, Max size of 10)\n");
		printf("Password #2: ");
		fgets(password, sizeof(password), stdin);
		cleanBuffers(password);

		hashPwd (salt, sizeof(salt), saltHash2);
		char saltedPwd2 [sizeof(password) + sizeof(saltHash2)];
		strncpy (saltedPwd2, password, sizeof(password));
		strncat (saltedPwd2, (char *)saltHash2, sizeof(saltHash2));
		hashPwd (saltedPwd2, sizeof(password), hash2);
		
		if (strncmp((char *)passwordOneHash, (char *) hash2, sizeof(hash2)) == 0) {
			//printf("yes\n");
			valid = 0;
		}
	}
    fclose(file);
	//printf("worked");
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

// TODO: change 0-9 will be {1, 10}
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
	if((regex(fileName, "^[a-zA-Z0-9]{1,50}.txt$") == 0) && strcasestr(fileName, "password.txt") == NULL )
		return 0;
	return 1;
}

// TODO: Change this to 1-10
int isValidPassword(char * password) {
    strip(password);
	size_t size = strlen(password);
	printf("valid password size: %d %s\n", (int)strlen(password), password);
	if(regex(password, "^[a-zA-Z0-9]{1,3}$") == 0)
		return 0;
	return 1;
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

void hashPwd(char *pwd, int bufSize, unsigned char *hash) {
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, (unsigned char*) pwd, bufSize);
    sha256_final(&ctx, hash);
}

