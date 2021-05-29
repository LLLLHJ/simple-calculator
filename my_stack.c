#include "my_stack.h"

Status Push_char(SqStack* S, char e) {
	if (S->top == MAXSIZE - 1) {
		return 0;
	}
	S->top++;
	S->data[S->top] = e;
	return 1;
}
Status Pop_char(SqStack* S, char* e) {
	if (S->top == -1) {
		return 0;
	}
	*e = S->data[S->top];
	S->top--;
	return 1;
}
Status Push_double(doubleSqStack* S, double e) {
	if (S->top == MAXSIZE - 1) {
		return 0;
	}
	S->top++;
	S->data[S->top] = e;
	return 1;
}
Status Pop_double(doubleSqStack* S, double* e) {
	if (S->top == -1) {
		return 0;
	}
	*e = S->data[S->top];
	S->top--;
	return 1;
}

