#include "output.h"
#include <string.h>
int output(char* str_input, int mode, char* path) {
	input(str_input, mode, path);
	char str_output[1000] = {'\0'};
	Conversion_expression(str_input, str_output);
	double ans = calc_expression(str_output);
	if (mode == 0) {
		printf("ans = %g\n", ans);
	}
	else {
        int i = 0;
		char str_ans[20] = {' ','=',' ','\0'};
		sprintf(str_ans + 3, "%g\n", ans);
		FILE* fp = fopen("./Input.out", "w");
        str_input[strlen(str_input)-1] = 0;
        fprintf(fp, "%s%s", str_input, str_ans);
        fclose(fp);
	}
	
	return 0;
	
}
