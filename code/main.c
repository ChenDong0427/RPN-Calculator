//
// Created by Chen Dong on 2021/12/2.
//
#include <stdio.h>
#include "rpn.h"
#include "errors.h"
#include "node.h"
#include "stack.h"
#include "convert.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]) {
    clearStack();
    char data[100];
    int status = NOERROR;
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    if(!input){
        perror("I/O error: in");
        return -1;
    }
    if(!output){
        perror("I/O error: out");
        return -1;
    }
    while(fgets(data,100,input)) {
        fprintf(output, "\nInfix: ");
        fprintf(output, data);
        char temp[100] = "\0";
        convert(data, temp, &status);
        if (status != 0){
            fprintf(output, "\nError: %s\n",error_handling[status]);
        }
        else{
            printf("\n%s\n", temp);
            fprintf(output, "Postfix: ");
            fprintf(output, temp);
            if (status == 0){
                double result = evaluate(temp, &status);
                printf("\n%f\n", result);
                fprintf(output,"\nResult: %f\n",result);
            }
            else{
                fprintf(output, "\nError: ");
                fprintf(output, error_handling[status]);
            }
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}
