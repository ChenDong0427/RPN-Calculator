//
// Created by Chen Dong on 2021/12/2.
//

#include "rpn.h"
#include <string.h>
#include "errors.h"
#include <stdlib.h>
#include "node.h"
#include "stack.h"
#include <stdio.h>
typedef struct node {
    union {
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    node *next;
} node;
node* cur;
double number1;
double count;
double evaluate (char* expression, int* status){
    clearStack();
    if (expression == NULL){
        *status =NONTOKEN;
        return 0;
    }
    if (strcmp(expression, " ")==0){
        *status =NONTOKEN;
        return 0.0;
    }
    char* token;
    token = strtok(expression," ");
    int count_op =0;
    int count_nm =0;
    while (token != NULL) {
        char *ptr;
        double result = 0;
        result = strtod(token, &ptr);
        char *temp = token;
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0 || strcmp(token, "^") == 0) {
            count_op++;
        }
        else if (result!=0){
            char temp_p;
            double value = strtod(temp, &temp_p);
            cur = createNumbernode(value, 1);
            push(cur);
            count_nm++;
            count++;
        }
        else{
            *status = INVALIDINPUT;
            return 0.0;
        }
        if (count_nm >= 2 && count_op == 1) {
            node *num1 = pop();
            node *num2 = pop();
            count_op = 0;
            number1 = calculate(num2->contents.value, num1->contents.value, *token);
            cur = createNumbernode(number1, 1);
            push(cur);
            count_nm--;
            free(num1);
            free(num2);
        }
        if (count_nm == 0 && count_op == 1) {
            *status = TOOMANYOPERATORS;
            return 0;
        }
        if (count_nm == 1 && count_op == 1) {
            *status = TOOMANYOPERATORS;
            return 0;
        }
        token = strtok(NULL, " ");
    }
    if (count <= 1) {
        *status = TOOFEWOPERATORS;
    }
    if (count_nm >=2){
        *status = TOOFEWOPERATORS;
    }
    return number1;
}
double calculate (double num1,double num2, char op){
    switch (op) {
        case '+':
            return add(num1, num2);
        case '-':
            return subtract(num1, num2);
        case '*':
            return multiply(num1, num2);
        case '/':
            return divide(num1, num2);
        case '^':
            return recursivePower(num1, num2);
        default:
            printf("operation sign is invalid");
            return 0;
    }
}
double add(double num1, double num2){
    double result = num1+num2;
    return result;
}
double subtract (double num1, double num2){
    double result = num1-num2;
    return result;
}
double multiply (double num1, double num2){
    double result = num1*num2;
    return result;
}
double divide (double num1, double num2){
    float result = num1/num2;
    return result;
}
double recursivePower (double num1, double num2) {
    if (num2 == 0) {
        return 1;
    }
    if (num2 == 1) {
        return num1;
    } else {
        num2--;
        return num1 * recursivePower(num1, num2);
    }
}





