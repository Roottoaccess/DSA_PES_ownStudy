#include<stdio.h>
#define n 5
int top = -1;
int stack[n];

void push(){
    // checking for thr first condition
    int data; printf("Enter the data: ");
    scanf("%d",&data);
    if(top == n - 1){
        printf("Stack is overflow !");
    }
    else {
        top++;
    stack[top] = data;
    }
}

void pop(){
    if(top == -1){
        printf("stack is underflow !");
    }
else{
       int demo = stack[top];
    top--;
    printf("poped item is %d", demo);
}
}

void peek(){
    if(top == -1){
        printf("stack is underflow !");
    }

    printf("peek result -> %d", stack[top]);
}

void display(){
    for(int i = top; i >= 0; i--){
        printf("%d", stack[i]);
    }
}

// int main(void){
//     printf()
// }