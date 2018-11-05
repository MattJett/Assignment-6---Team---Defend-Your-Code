#include "myUtils.h"

void strip(char * array) {
	if(array == NULL) {
			perror("array is null");
			exit(-99);
	}

	int len = strlen(array), x = 0;
   
	while(array[x] != '\0' && x < len){
	  if(array[x] == '\r')
		 array[x] = '\0';
	  else if(array[x] == '\n')
		 array[x] = '\0';
	  x++;

	}
}

//User Inputs
// dummy is 5, expect string 1-3. last character is for \n. 2nd to last character is to test if its over 3.
// 1234 => last character is \n, then its just 1234 and 2nd to last shows 4 is extra digit so it fails.
void getFname(char * fname, size_t len){
	int valid = -1;
	char input[52];
	
	while(valid == -1) {
		printf("Enter First name (Between 1 to 50 characters. ONLY accepting letters)\n");
		printf("First Name: ");
		fgets(input, (sizeof(input)), stdin);
		cleanBuffers(input);
		if(isValidName(input) == 0)
			valid = 0; // to test, change this to -1
		else
			printf("Your name input is invalid please try again! \n");	
	}
   strncpy(fname, input, len);	
}

// also do we need to flush stdin?
void getLname(char * lname, size_t len){
    int valid = -1;
	char input[52];
	
	while(valid == -1) {
		printf("Enter Last name (Up to 50 characters. ONLY accepting letters)\n");
		printf("Last Name: ");
		fgets(input, (sizeof(input)), stdin);
		cleanBuffers(input);
		if(isValidName(input) == 0)
			valid = 0;
		else
			printf("Your name input is invalid please try again!\n");	
	}
   strncpy(lname, input, len);	
}

// TODO: 000000000000000000001 should just convert to 1??? at this point sake of time, dont really care too much...
//wants 3 digits. +1 to check minus sign. +1 for \n. +1 for both minus and \n
//hard to conceptualize but test it around it makes sense.
long getNum1() {
	int valid = -1;
	long num = 0;
	char input[15];
	
	while(valid == -1) {
		printf("\nEnter First Integer (Only digits between -2147483648 to 2147483647)\n");
		printf("Num1: ");
		fgets(input, (sizeof(input)), stdin);
		cleanBuffers(input);
		if(isValidNum(input) == 0) {
			valid = 0; // to test, change this to -1
			num = atol(input);
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
	
	while(valid == -1) {
		printf("Enter Second Integer (Only digits between -2147483648 to 2147483647)\n");
		printf("Num2: ");
		fgets(input, (sizeof(input)), stdin);
		cleanBuffers(input);
		if(isValidNum(input) == 0) {
			valid = 0; // to test, change this to -1
			num = atol(input);
		} else {
			printf("Your name input is invalid please try again! \n");	
		}
	}
	return num;
}

void getInputFile(FILE * file, char * name) {
	char input[56];

	printf("\nEnter name of text Input file in this directory (Name of file (ignoring extension) must be no larger than 50 characters. Accepting ONLY .txt files AND ONLY letters and numbers.)\n");
	printf("Input File: ");
	fgets(input, (sizeof(input)), stdin);
	cleanBuffers(input);
	while ((file = fileValidation(input, sizeof(input), 0)) == NULL)
	{
		printf("\nEnter name of text Input file in this directory (Up to 50 characters. Accepting ONLY .txt files AND ONLY letters and numbers)\n");
		printf("Input File: ");
		fgets(input, (sizeof(input)), stdin);
		cleanBuffers(input);
	}
}

void getOutputFile(FILE * writeToFile, char * writeFileName, char * readFileName) {
	char input[56];

	printf("Enter name of text Output file in this directory thats not the same as the entered input file name.\n (Name of file (ignoring extension) must be no larger than 50 characters. Accepting ONLY .txt files AND ONLY letters and numbers.)\n");
	printf("Output File: ");
	fgets(input, (sizeof(input)), stdin);
	cleanBuffers(input);

	while ((writeToFile = fileValidation(input, sizeof(input), 1) == NULL) && (strcmp(input, readFileName) != 0))
	{
		printf("\nEnter name of text Input file in this directory (Up to 50 characters. Accepting ONLY .txt files AND ONLY letters and numbers)\n");
		printf("Input File: ");
		fgets(input, (sizeof(input)), stdin);
		cleanBuffers(input);
	}
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
int isValidName(char * name) {
	strip(name);
    size_t size = strlen(name);
	if(regex(name,"^[a-zA-Z]{1,50}$") == 0)
		return 0;
	return 1;
}

int isValidNum(char * num) {
    strip(num);
	size_t size = strlen(num);
	if(regex(num,"^[\\-]?([0-9]{1,10})$") == 0)
		return 0;
	return 1;
}

int isValidPassword(char * password) {
    strip(password);
	size_t size = strlen(password);
	printf("valid password size: %d %s\n", (int)strlen(password), password);
	if(regex(password, "^[a-zA-Z0-9]{1,10}$") == 0)
		return 0;
	return 1;
}

// Modified by using https://wiki.sei.cmu.edu/confluence/display/c/FIO03-C.+Do+not+make+assumptions+about+fopen%28%29+and+file+creation
FILE * fileValidation(char * name, size_t len, int isWritable) {
	FILE * file;
	char * fileType;
	strip(name);
	if((regex(name, "^[a-zA-Z0-9]{1,54}.txt$") == 0) && strcasestr(name, "password.txt") == NULL)
	{
		if(isWritable == 0)
			fileType = "r";
		else
			fileType = "w";

		if(fopen_s(&file, name, fileType) != 0)
		{
			file = NULL;
			printf("NOTICE: File must be in the same directory as this program's executable.\n");
        	return file;
		}
	}
	return file;
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

void printToFile(FILE * outputFile, FILE * inputFile, char * lastName, char * firstName, long num1, long num2)
{
	long long sumNum = (long long) num1 + num2;
    long long productNum = (long long) num1 * num2;
    
    char sumString[256];
	char productString[256];
    _ui64toa(sumNum, sumString, 10);
    _ui64toa(productNum, productString, 10);

	fprintf(outputFile, "Name: %s, %s\nSum: %s\nProduct: %s\n", lastName, firstName, sumString, productString);
	char c = fgetc(inputFile);
    while(c != EOF)
    {
        fputc(c, outputFile);
        c = fgetc(inputFile);
    }
    
    fclose(inputFile);
    fclose(outputFile);
	getchar();
}

