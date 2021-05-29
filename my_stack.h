#pragma once
#include <stdio.h>

#define MAXSIZE 1000

typedef int Status;
typedef struct {
	char data[MAXSIZE];
	int top;
}SqStack;
typedef struct {
	double data[MAXSIZE];
	int top;
}doubleSqStack;


Status Push_char(SqStack* S, char e);
Status Pop_char(SqStack* S, char* e);
Status Push_double(doubleSqStack* S, double e);
Status Pop_double(doubleSqStack* S, double* e);



