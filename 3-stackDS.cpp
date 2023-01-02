//
// Created by kaung007 on 12/29/22.
//

#include "stdio.h"
#include "stdlib.h"

#define MAXOFSTACK 10

struct stack{

    int data[MAXOFSTACK];
    int top;   // data lock

};

typedef struct stack st;

int isStackIsFull(st *myStack){
    if(myStack->top == MAXOFSTACK - 1) return 1;
    else return 0;
}

int isStackIsEmpty(st *myStack){
    if(myStack->top == -1) return 1;
    else return 0;
}

void creatEmptyStack(st* myStack){

    myStack->top = -1;

}

void pushToStack(st *myStack, int value){

    if(isStackIsFull(myStack)){
        printf("Stack is FULL!!\n");
    } else {
        myStack->top++;

        myStack->data[myStack->top] = value;
    }

}

void popFromStack(st *myStack){

    if(isStackIsEmpty(myStack)){
        printf("Stack is empty!!!\n");
    } else {
        printf("Pop from stack data is: %d\n", myStack->data[myStack->top]);
        myStack->top--;
    }

}

void stackData(st *myStack){

    if(myStack->data == NULL){
        printf("Stack haven't data!!\n");
    } else {
        printf("Data in the stack\n");
        for (int i = myStack->top; i >= 0  ; i--) {
            printf("index: %d; Stack Data: %d\n",i,myStack->data[i]);
        }
    }

}


int main(){

    st *myStack = (st *)malloc(sizeof(st));

    creatEmptyStack(myStack);

    pushToStack(myStack,1);
    pushToStack(myStack,10);
    pushToStack(myStack,12);
    pushToStack(myStack,15);
    pushToStack(myStack,20);
    pushToStack(myStack,22);

    stackData(myStack);
    int length = sizeof(myStack->data)/ sizeof(myStack->data[0]);

    for (int i = 0; i < length; i++) {
        if(myStack->top == -1) return 0;
        else popFromStack(myStack);
    }

//    popFromStack(myStack);
//    popFromStack(myStack);
//    popFromStack(myStack);
//    popFromStack(myStack);
//    popFromStack(myStack);


    return 0;
}
