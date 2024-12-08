#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *link;
}*node;

// creating the node
node create_node(int data){

    // creating the memory
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    n -> data = data;
    n -> link = n;

    return n;
}

// void display
node display(node n){
    if(n == NULL){
        printf("")
    }
}