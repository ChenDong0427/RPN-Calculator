//
// Created by Chen Dong on 2021/12/2.
//

#ifndef PS5_NODE_H
#define PS5_NODE_H
typedef struct node node;
node* createOperatorNode(char, int);
node* createNumbernode(double, int );
typedef enum type{operator = 0, number = 1};
#endif //PS5_NODE_H
