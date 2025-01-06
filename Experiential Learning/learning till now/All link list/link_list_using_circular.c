// creating the circular link list
#include<stdio.h>
#include<stdlib.h>

// creating the structure
typedef struct node{
    int data;
    struct node *link;
}*node;

// create_node 
node create_node(int data){
    node n = (node) malloc (sizeof(node));
    if(n == NULL){
        printf("");
    }
}