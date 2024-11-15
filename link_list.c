// defining the header files
#include<stdio.h>
#include<stdlib.h>

// Creating the struct for using the NODE datatype
// Dtatype is constant
typedef struct mynode
{
    /* data */
    int data;
    struct mynode *link;
    
} *NODE;
// This is another function for creating the node.....
NODE create_node (int data){
    NODE temp = (NODE) malloc (sizeof(NODE));

    if(temp != NULL){
        temp -> data = data;
        temp -> link = NULL;
    } else{
        printf("\n\t Unable to create a Node");
    }
    return temp;
}
// Travertion function
void Display(NODE Head){
    if(Head == NULL){
        printf("Empty list");
    } else {
        printf("\n Head -> ");
        for(NODE temp = Head; temp != NULL; temp = temp -> link){
            printf(" %d ->",temp->data);
        }
        printf(" NULL \n");
    }
}
// function for the insertion....
NODE ins_front(NODE Head, int data){
    NODE new_node = create_node(data);
    if(new_node != NULL){
        new_node  -> link= Head;
        Head = new_node;
    }
    return new_node;
}


// main function.....
int main(void){

    
}