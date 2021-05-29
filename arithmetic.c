/*************************************************************************
	> File Name: arithmetic.c
	> Author: 
	> Mail: 
	> Created Time: Fri 21 May 2021 09:01:03 PM CST
 ************************************************************************/

#include "arirhmetic.h"

double add(double a, double b){
    return a + b;
}
double minus(double a, double b){
    return a - b;
}
double multiply(double a, double b){
    return a * b;
}
double divide(double a, double b){
    if(b == 0){
        printf("the dividend can not be 0!");
        return 0;
    }
    return a / b;
}

