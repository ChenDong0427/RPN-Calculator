//
// Created by Chen Dong on 2021/12/4.
//

#include "convert.h"
#include <stdio.h>
#include "rpn.h"
#include "node.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include "errors.h"
typedef struct node {
    union {
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    node *next;
} node;
void removes(char* input){ // This is the method TA told me to use for removing the "\n"
    size_t len = strlen(input);
    while((len>0) && (input[len-1] == '\n')){
        len--;
        input[len] ='\0';
    }
}

void convert(char* input,char* output,int*status){
    removes(input);
    char *ptr;
    char temp[2];
    char outputstring;
    *status = NOERROR;
    char* token = strtok(input," ");
    while(token) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0||strcmp(token, "*") == 0
        ||strcmp(token, "/") == 0||strcmp(token, "^") == 0) {
            outputstring= token[0];
            node *ope = createOperatorNode(outputstring,operator);
            if(peek()) {
                while ((peek() && (peek()->precedence >= ope->precedence && peek()->contents.operator !='('))) {
                    temp[0] = peek()->contents.operator;
                    strcat(output, temp);
                    strcat(output, " ");
                    node *node1 = pop();
                    free(node1);
                }
            }
            push(ope);
        }
        else if (strcmp(token, "(") == 0) {
            outputstring = token[0];
            node *node = createOperatorNode(outputstring, operator);
            push(node);
        }
        else if (strcmp(token, ")") == 0) {
            while (peek() && peek()->contents.operator != '(') {
                node *node1 = pop();
                temp[0] = node1->contents.operator;
                strcat(output, temp);
                strcat(output, " ");
                free(node1);
            }
            if (peek() == NULL) {
                *status = MISMATCHEDPARENTHESIS;
                return;
            }
            else if (peek()->contents.operator == '(') {
                node *node1 = pop();
                free(node1);
            }
        }
        else {
            double result = 0;
            result = strtod(token, &ptr);
            if (result != 0) {
                strcat(output, token);
                strcat(output, " ");
            }
            else {
                *status = INVALIDINPUT;
                return;
            }
        }
        token = strtok(NULL, " ");
    }
    while(peek()!= NULL) {
        node *new = peek();
        if (new->contents.operator == "(" || new->contents.operator == ')') {
            *status = MISMATCHEDPARENTHESIS;
            return;
        }
        else {
            temp[0] = new->contents.operator;
            strcat(output, temp);
            strcat(output, " ");
            free(pop());
        }
    }
    clearStack();
}























