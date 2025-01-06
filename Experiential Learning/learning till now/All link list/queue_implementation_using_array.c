#include<stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

// creating the enqueue function
void enqueue(int data){
    if(rear == N - 1){
        printf("Queue Overflow !");
    } else if(front == -1 && rear == -1){
        front = rear = 0;

        queue[rear] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}
// creating the display function
void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow condition !");
    }
    else if(front == rear){
        front = rear = -1;
    } else {
        printf("The dequeued element is %d \n",queue[front]);
        front++;
    }
}
// creating the display function
void display(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty Now Please insert value inside the queue");
    }
    else{
        for(int i = front; i <= rear; i++){
            printf("| %d |\n", queue[i]);
        }
    }
}

// Creating the Peek function
void Peek(){
    if(front == -1 && rear == -1){
        printf("The Queue is Empty !");
    }
    else{
        printf("PEEK -> | %d |\n", queue[front]);
    }
}

// creating the main function to perform the queue operations
int main(void){
    enqueue(2);
    enqueue(4);
    enqueue(6);
    enqueue(8);
    display();
    dequeue();
    display();
    Peek();
}