// This is the doubly link list program ....
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;  
}*node;

node create_node(int data){
    node n = (node) malloc (sizeof(node));
    if(n == NULL){
        printf("Memory allocation failed !");
    }
    n -> next = NULL;
    n -> data = data;
    n -> prev = NULL;

    return n;   }

node ins_in_front(node n, int data){
    // creating the new node
    node new_node = create_node(data);

    new_node -> next = n;
    new_node -> prev = NULL;
    n -> prev = new_node;

    return new_node;  
}
node ins_in_rear(node n, int data){ 
    node new_node = create_node(data);

    node temp = n;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = new_node;
    new_node -> prev = temp;
    new_node -> next = NULL;

    return n;
}

void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
    }

    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ", n -> data);
        n = n -> next;
    }
    printf("NULL \n");  
}


int main(void){
    node head = create_node(2);
    display(head);
    head = ins_in_front(head, 4);
    display(head);
    head = ins_in_rear(head, 5);
    display(head);
}