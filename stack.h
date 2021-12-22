//
// Created by Chen Dong on 2021/12/2.
//

#ifndef PS5_STACK_H
#define PS5_STACK_H
#include <stdbool.h>
typedef struct node node;
void push(node*); //Push a node onto the stack
node* pop(void); //Pop the top of the stack
node* peek(void); //Return a reference to the node on top of the stack
bool stackEmpty(void); //Check if the stack is empty
void clearStack(void); //Clear the stack


#endif //PS5_STACK_H
