/*************************************************************************
	> File Name: input_test.c
	> Author: 
	> Mail: 
	> Created Time: Thu 20 May 2021 11:18:15 AM CST
 ************************************************************************/

#include "input_test.h"

void input(char *p, int mode, char *path){
    if(mode == 0){
        scanf("%s", p);
    }

    else{
        char temp;
        int offset = 0;
        FILE *fp = fopen(path, "r");
        while(fscanf(fp,"%c", &temp) != EOF){
           offset  +=  sprintf(p+offset,"%c", temp);
        }
    }
    
	//printf("%s", p);
}
