#include<stdio.h>
#include<stdlib.h>

typedef struct MyStackADT{
    int *array;
    int top;
    int capacity;
}*Stack;

Stack CreateStack(int capacity){
    Stack NewStack = (Stack)malloc(sizeof(struct MyStackADT));

    if(NewStack == NULL){
        printf("\n\t\t Insufficient Memory !!! Exiting !!!!");

        exit(EXIT_FAILURE);
    }

    NewStack -> array = (int *)malloc(sizeof(int) * capacity);
    if(NewStack -> array == NULL){
        printf("\n\t\t Insufficient Memory !!! Exiting !!!!");
        exit(EXIT_FAILURE);
    }

    NewStack->top = -1;
    NewStack -> capacity = capacity;

    printf("\n\t\t Successfully Created Stack ADT");

    return NewStack;
}

int Do_Resize(Stack MyStack, int inc_dec){
    int NewSize = MyStack -> capacity + inc_dec;
    int *NewArray = (int *)realloc(MyStack -> array, sizeof(int) * NewSize);

    if(NewArray == NULL){
        printf("\n\t\t Insufficient Memory !!! Exiting !!!!");
        return 0;
    }

    MyStack->capacity = NewSize;
    MyStack->array = NewArray;
    return 1;
}

void push(Stack MyStack){
    int element, status;
    printf("\n\t\t Enter the element to be pushed onto the stack: ");
    scanf("%d")
}