// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node *link;
// }*node;

// node create_node(int data){
//     node n = (node) malloc (sizeof(node));

//     if(n == NULL){
//         printf("Memory allocation failed !");
//     }

//     n -> data = data;
//     n -> link = n;
//     return n;
// }

// void display(node n){
//     if(n == NULL){
//         printf("There is no node present in the memory !");
//     }
//     node temp = n;
//     // while(temp -> link != n){
//     //     temp = temp -> link;
//     //     printf("%d -> ",temp -> data);
//     // }
//     do{
//         temp = temp -> link;
//         printf("%d -> ", temp -> data);
//     }while(temp != n);
// }

// node ins_in_front(node n, int data){
//     node new_node = create_node(data);
//     node temp = n;
//     do{
//         temp = temp -> link;
//     }while(temp -> link != n);

//     temp -> link = new_node;
//     new_node -> link = n;

//     return new_node;
// }

// int main(void){
//     node head =create_node(2);
//     display(head);
//     head = ins_in_front(head, 4);
//     display(head);
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *node;

node create_node(int data) {
    node n = (node) malloc(sizeof(struct node)); // Correct allocation
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit program if memory allocation fails
    }

    n->data = data;
    n->link = n;
    return n;
}

void display(node n) {
    if (n == NULL) {
        printf("There is no node present in the memory!\n");
        return; // Exit the function
    }

    node temp = n;
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != n); // Corrected traversal condition
    printf("NULL\n");
}

node ins_in_front(node n, int data) {
    node new_node = create_node(data);
    if (n == NULL) {
        return new_node; // New node becomes the only node in the list
    }

    node temp = n;
    // Traverse to the last node
    do {
        temp = temp->link;
    } while (temp->link != n);

    temp->link = new_node; // Update the last node to point to new node
    new_node->link = n;    // New node points to the head

    return new_node; // New node becomes the new head
}

node ins_at_last(node n, int data){
    node new_node = create_node(data);
    // if (n == NULL) {
    //     // If the list is empty, point the new node to itself and return
    //     new_node->link = new_node;
    //     return new_node;
    // }
    node temp = n;
    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = new_node;
    new_node -> link = n;

    return n;
}

int main(void) {
    node head = create_node(2);
    display(head);

    head = ins_in_front(head, 4);
    display(head);

    head = ins_in_front(head, 6);
    display(head);

    head = ins_at_last(head, 12);
    display(head);
    return 0;
}
