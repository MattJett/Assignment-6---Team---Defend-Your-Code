#ifndef MYUTILS_H
#define MYUTILS_H
//#define _XOPEN_SOURCE
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <unistd.h>
#include <crypt.h>
#include <time.h>
#include <sys/wait.h>
#include "sha256.h"

void strip(char * array);

//User Inputs
void getFname(char * fname, size_t len);
void getLname(char * lname, size_t len);

long getNum1();
long getNum2();

void getInputFile(FILE * input, char * name);
void getOutputFile(FILE * output, char * outputName, char * inputName);

void getPassword();

// Validation
int isValidName(char * name);
int isValidNum(char * num);
int isValidPassword(char * password);
FILE * fileValidation(char * name, size_t len, int isWritable);
int regex(char * string, char * test);
void cleanBuffers(char * buf);
void hashPwd(char *pwd, int bufSize, unsigned char *hash);
void printToFile(FILE * output, FILE * input, char * lastName, char * firstName, long num1, long num2);
#endif
