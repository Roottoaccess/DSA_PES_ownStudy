// implementing stack using array
#include<stdio.h>
#define max 5
int stack[max];
int top = -1;
// creating the push operation
void push(){
    int data; printf("Enter data: ");
    scanf("%d",&data);
    if(top == max - 1){
        printf("stack Overflow\n");
    }
    else{
        top++;
        stack[top] = data;
    }
}

// creating the display operation
void display(){
    if(top == -1){
        printf("There is no element present in the stack !\n");
    }
    // printf("TOP -> ");
    for(int i = top; i >= 0; i--){
        printf(" | %d | \n", stack[i]);
    }
}

// creating the pop function
void pop(){
    if(top == -1){
        printf("Stack Underflow !\n");
    }
    int demo = stack[top];
    top--;
    printf("\nPoped element -> %d\n", demo);
}

// creating the peek function
void peek(){
    if(top == -1){
        printf("There is no element present in the stack !");
    } else {
        printf("\nPEEK -> %d\n",stack[top]);
    }
}

int main(void){
    push();
    push();
    display();
    pop();
    printf("\n");
    push();
    push();
    display();
    peek();
    return 0;
}