#include <stdio.h>
#include "calc.h"
#include "input_test.h"
#include "output.h"
char str_input[1000] = {'\0'};
char* path = "./Input";
char str_output[1000] = {'\0'};
int mode = 0;
int main(int argc, char *argv[] ) {
    if(argc > 1){
        if(argv[1][0] == '1') mode = 1;
    }
    /*
    input(str_input, mode, path);
    Conversion_expression(str_input, str_output);
    double ans = calc_expression(str_output);
    printf("%g\n", ans);*/
	output(str_input, mode, path);
	return 0;
}
