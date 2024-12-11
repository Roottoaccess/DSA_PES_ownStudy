// stack using the singly link list....
#include<stdio.h>
#include<stdlib.h>

// creating the structure node
typedef struct node{
    int data;
    struct node *link;
}*node;


// creating the node
node create_node(int data){
    // dynamic memory allocation

    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed");
        return NULL;
    }

    n -> data = data;
    n ->link = NULL;

    return n;
}

// display_function
void display(node n){
    if(n == NULL){
        printf("There is nothing to display !");
    }

    printf("TOP -> ");

    while(n != NULL){
        printf("%d -> ",n -> data);

        n = n -> link;
    }

    printf("TAIL\n");
}

// creating the push operation
node push(node n, int data){

    // creating the new node
    node new_node = create_node(data);

    if(new_node == NULL){
        printf("Not possible !");
    }

    new_node -> link = n;

    return new_node;
}

// creating the pop function
node pop(node n){

    // same as deleteing in front
    if(n == NULL){
        printf("Delete not possible because there is no node in the memory");
    }

    node temp = n;
    n = n-> link;
    free(temp);
    return n;
}

// creating the peek operation
node peek(node n){

    if(n == NULL){
        printf("There is no node present in the memory !");
    }

    printf("Peek -> %d \n", n -> data);

    return 0;
}

// creating the main function for calling the function
int main(void){

    // calling the functions
    node head = create_node(1);
    display(head);
    head = push(head, 2);
    display(head);
    head= pop(head);
    display(head);
    head = peek(head);
}
