//
// Created by Chen Dong on 2021/12/2.
//

#ifndef PS5_RPN_H
#define PS5_RPN_H
double evaluate (char* expression, int* status);
int isEqual(char* expression);
double calculate (double number1,double number2, char op1);
double add(double num1, double num2);
double subtract (double num1, double num2);
double multiply (double num1, double num2);
double divide (double num1, double num2);
double recursivePower (double num1, double num2) ;
#endif //PS5_RPN_H
