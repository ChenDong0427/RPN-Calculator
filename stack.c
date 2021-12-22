//
// Created by Chen Dong on 2021/12/2.
//

#include "stack.h"
#include "node.h"
#include <stdlib.h>
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

node* HEAD = NULL;
node* temp = NULL;
void push(node* node)  {
    if (node == NULL){
        return;
    }
    if (HEAD == NULL){
        HEAD = node;
        return;
    }
    temp = HEAD;
    HEAD = node;
    node->next = temp;
}
node* pop(){
    node* cur = HEAD;
    HEAD = HEAD->next;
    return cur;
}
node* peek(){
    temp = HEAD;
    return temp;
}
void clearStack(){
    if(HEAD==NULL){
        return;
    }
    while(HEAD!=NULL){
        node* cur =HEAD;
        pop();
        HEAD = HEAD->next;
        free(cur);
    }
}





