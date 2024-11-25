#include<stdio.h>
#include<stdlib.h>

// Creating the user define datatype

typedef struct node{
    int data;
    struct node *next;
}*node;

// create a node
node create_node(){
    /* Dynamic memory allocation */
    node n = (node)malloc(sizeof(node));
    if(n == NULL){
        printf("Memory allocation failed !");
    }
    printf("Enter data: ");
    scanf("%d",&n->data);
    n->next = NULL;

    return n;
}

void display(node n){
    printf("HEAD -> ");
    while(n!=NULL){
        printf("%d -> ",n->data);

        n = n->next;
    }
    printf("NULL \n");
}

node ins_front(node n){
    node new_node = create_node();

    new_node->next = n;
    return new_node; 
}

// node ins_last(node n){
//     node new_node = create_node();

//     // Creating an temp node for holding the actual node
//     if(n == NULL){
//         return new_node;
//     }
//     node temp = n;
//     while(temp->next != NULL){
//         temp = temp->next;
//     }
//     temp->next = new_node;
//     return n;
// }

node ins_last(node n){
    node new_node = create_node();

    if(n == NULL){
        return new_node;
    }
    node temp = n;
    while(temp->next != NULL){
        temp= temp->next;
    }
    temp-> next = new_node;
    return n;
}


int main(void){
    node n = create_node();
    display(n);
    n = ins_front(n);
    display(n);
    n = ins_last(n);
    display(n);
}