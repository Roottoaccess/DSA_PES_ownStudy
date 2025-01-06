/* Program for implementing queue using link list */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{ // Creating the structure of the queue implementation
    int data;
    struct node *link;
}*node;

// create node function
node create_node(int data){
    // dynamic memory allocation
    node head = (node) malloc (sizeof(struct node));
    if(head == NULL){
        printf("Dynamic memory allocation failed !");
    }

    head -> data = data;
    head -> link = NULL;
    return head;
}

// displaying the queue
void display(node head){
    if(head == NULL){
        printf("There is no node present in the queue to display !!");
    }

    printf("Queue Started\n");
    while(head != NULL){
        printf("\t\t| %d | \n", head -> data);
        head = head -> link;
    } printf("Queue Ended \n");
}

// Enqueue operation using link list
node Enqueue(node head, int data){
    node new_node = create_node(data);
     if(head == NULL){
        return create_node(data);
    }
    if(new_node == NULL){
        printf("Element Enqueue Error occured due to something !!");
    }
    node temp = head;
    while(temp -> link != NULL){
        temp = temp -> link;
    }

    temp -> link = new_node;

    new_node -> link = NULL;

    return head;
}

// creating the Dequeue function with the help of link list
node Dequeue(node head){
    if(head == NULL){
        printf("There is no element present to perform the Dequeue function !!");
    }

    node temp = head;
    head = head -> link;
    free(temp);
    return head;
}

// Peek operation using the link list....
void Peek(node head){
    
}

int main(void){
    node head = create_node(2);
    display(head);
    head = Enqueue(head, 4);
    display(head);
    head = Dequeue(head);
    display(head);
}