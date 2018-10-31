#ifndef MYUTILS_H
#define MYUTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void strip(char * array);

//User Inputs
void getFname(char * fname, size_t len);
void getLname(char * lname, size_t len);

long getNum1();
long getNum2();

void getInput(char * inputName, size_t len);
void getOutput(char * outputName, char * inputName, size_t len);

void getPassword();

// Validation
bool isValidName(char * name);
bool isValidNum(char * num);
bool isValidFileName(char * fileName);
bool isValidPassword(char * password);


#endif