//
// Created by Chen Dong on 2021/12/2.
//

#include "node.h"
#include "stack.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef struct node {
    union {
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    node *next;
} node;

node* createOperatorNode(char operator, int type){
    node *newNode = (struct node *) malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }
    memset(newNode,0,sizeof(node));
    newNode-> contents.operator = operator;
    newNode->type = type;
    newNode->next = NULL;

    if(operator == '+' || operator =='-') {
        newNode->precedence = 1;
    }
    else if(operator == '*' || operator == '/'){
        newNode->precedence = 2;
    }
    else if(operator == '^' ){
        newNode->precedence = 3;
    }
    else{
        newNode ->precedence = 0;
    }
    return newNode;
}
node* createNumbernode(double value, int type){
    node *newNode = (struct node *) malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }
    newNode-> contents.value = value;
    newNode->type = type;
    newNode->next = NULL;
    return newNode;
}




