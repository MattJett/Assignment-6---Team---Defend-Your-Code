// Hung Auduong
// Matthew Jetts
// C-Implementation

#ifndef MYUTILS_H
#define MYUTILS_H
#define _XOPEN_SOURCE
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

void getInputFile(char * inputName, size_t len);
void getOutputFile(char * outputName, char * inputName, size_t len);

void getPassword();

// Validation
int isValidName(char * name);
int isValidNum(char * num);
int isValidFileName(char * name);
int isValidPassword(char * password);
int regex(char * string, char * test);
void cleanBuffers(char * buf);
void hashPwd(char *pwd, int bufSize, unsigned char *hash);
void printToFile(char * in, char * out, char * lastName, char * firstName, long num1, long num2);
#endif
