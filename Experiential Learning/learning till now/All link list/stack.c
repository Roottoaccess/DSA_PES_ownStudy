// creating the stack
#include<stdio.h>
#include<stdlib.h>

// defining the maximum value!
#define Max 5

int top = -1;
int stack[Max];
void push(){
    if(top == Max - 1){
        printf("Stack Overflow !");
    }
    int data; printf("Enter the data: ");
    scanf("%d",&data);

    top ++;

    stack[top] = data;
    
}

void pop(){
    if(top == -1){
        printf("Stack Underflow !");
    }

    int demo = stack[top];

    top--;

    printf("poped item is -> %d", demo);
}

void peek(){
    if(top == -1){
        printf("Stack is underflow !");
    }

    printf("\nPeek -> |%d|\n", stack[top]);
}

void display(){
    if(top == -1){
        printf("Stack underflow !");
    }
    printf("\n<-- STACK -->\n");
    for(int i = top; i >= 0; i--){
        printf("\t\t|%d|\n", stack[i]);
    }
}

int main(void){
    int choice;
    while(1){
        printf("\n\n1.Push()\n2.Display()\n3.Pop()\n4.Peek()\n5.EXIT\n");
        printf("\n\nEnter your choice: "); scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                display();
                break;
            case 3:
                pop();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting from the program ....\n");
                exit(0);
            default:
                printf("Please select a valid option");
        }
    }
}