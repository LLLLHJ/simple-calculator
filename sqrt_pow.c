/*************************************************************************
	> File Name: sqrt_pow.c
	> Author: 
	> Mail: 
	> Created Time: Sat 22 May 2021 08:14:01 PM CST
 ************************************************************************/
#include "sqrt_pow.h"
double sqrt(double x){
    if(x < 0){
        printf("ERROR\n");
        return 0;
    }
    else{
        double start,mid,last;
        start = 0.0;
        last = x;
        if(x < 1.0) last = 1.0;
        mid = (start + last) / 2.0;
        do{
            if(mid * mid > x) last = mid;
            else start = mid;
            mid = (start + last) / 2.0;
        }while((mid - start) > eps);
        return mid;
    }
    return 0;
}
double Pow(double x, int n){
    double ans = 1.0;
    if(n == 0) return 1;
    if(n < 0){
        x = 1.0 / x;
        n = -n;
    }
    while(n){
        if(n & 1){
            ans *= x;
        }
        n >>= 1;
        x *= x;
    }
    return ans;
}
