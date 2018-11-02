#ifndef MYUTILS_H
#define MYUTILS_H
#define _XOPEN_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <unistd.h>
//#include <crypt.h>
#include <Wincrypt.h>
#include <windows.h>
#include <time.h>
#include "sha256.h"

void strip(char * array);

//User Inputs
void getFname(char * fname, size_t len);
void getLname(char * lname, size_t len);

long getNum1();
long getNum2();

void getInputFile(char * inputName, size_t len);
void getOutputFile(char * outputName, size_t len);

void getPassword();

// Validation
int isValidName(char * name);
int isValidNum(char * num);
int isValidFileName(char * fileName);
int isValidPassword(char * password);
int regex(char * string, char * test);
void cleanBuffers(char * buf);
