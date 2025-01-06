#include<stdio.h>
#include<stdlib.h>

// Defining the max value as 5
#define n 5

// Creating the array with the limit
int stack[n];
int top = -1;

// Performing the push operation
void push() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);

    if (top == n - 1) { // condition check for the overflow
        printf("Stack is Overflow!\n");
    } else {
        top++;
        stack[top] = data;
    }
}

// Performing the pop operation in the stack
void pop() {
    if (top == -1) {
        printf("The Stack is Underflow!\n");
    } else {
        int item = stack[top];
        top--;
        printf("Popped element: %d\n", item);
    }
}

// Performing the peek operation
void peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Display operation
void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("\n\t|%d| ", stack[i]);
        }
        printf("\n");
    }
}

int main(void) {
    int choice; 
    while (1) {
        printf("\n1 for Push\n2 for Pop\n3 for Peek\n4 for Display\n5 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting ....\n");
                exit(0);
            default:
                printf("You entered an incorrect input!!\n");
        }
    }
}
