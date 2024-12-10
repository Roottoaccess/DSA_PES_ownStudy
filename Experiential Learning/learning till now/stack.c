// implementing the stack
#include<stdio.h>
// defining 10 as constant
#define MAX 10
// creating the structure
typedef struct StackADT{
    int stk[MAX];
    int TOP;
}*Stack;
// Checking if the stack is full
int IsFull(Stack MyStack){
    return ((MyStack -> TOP) == (MAX - 1) ? 1: 0);
}
// Checking if the stack is Empty
int IsEmpty(Stack MyStack){
    return ((MyStack->TOP) == -1 ? 1 : 0);
}
// This is the display operation..
void display(Stack MyStack) {
    if (IsEmpty(MyStack)) {
        printf("\n\t\t Stack is Empty\n");
    } else {
        printf("\n\t\t TOP -> | ");
        for (int i = MyStack->TOP; i >= 0; i--) {
            printf("%d | ", MyStack->stk[i]);
        }
        printf("\n");
    }
}
// Peek function
void peek(Stack MyStack) {
    if (IsEmpty(MyStack)) {
        printf("\n\t\t Stack is Empty. Nothing to Peek\n");
    } else {
        printf("\n\t\t Top element is: %d\n", MyStack->stk[MyStack->TOP]);
    }
}
// This is the push operation....
void push(Stack MyStack){
    int element;
    if(IsFull(MyStack)){
        printf("\n\t\t Stack Overflow");
    }
    else{
        printf("\n\t\t Enter the element : ");
        scanf("%d",&element);

        MyStack -> stk[++MyStack->TOP] = element;
    }
    display(MyStack);
}
// This is the POP operation....
void pop(Stack MyStack){
    if(IsEmpty(MyStack)){
        printf("\n\t\t Stack Underflow !!!");
    }
    else{
        printf("\n\t\t %d is Popped", MyStack->stk[(MyStack->TOP)--]);
    }
    display(MyStack);
}
// Defining the main function for the execution
int main(void){
    struct StackADT myStackInstance;
    myStackInstance.TOP = -1; // Initialize stack
    Stack MyStack = &myStackInstance;

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("5. Peek\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(MyStack);
                break;
            case 2:
                pop(MyStack);
                break;
            case 3:
                display(MyStack);
                break;
            case 4:
                printf("\n\t\t Exiting...\n");
                break;
            case 5:
                peek(MyStack);
                break;
            default:
                printf("\n\t\t Invalid Choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}