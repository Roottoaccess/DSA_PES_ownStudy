// creating the circular link list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*node;

// create node function
node create_node(int data){
    // dynamic memory allocation
    node n = (node) malloc (sizeof(struct node));
    if(n == NULL){
        printf("Memory allocation failed !");
    }

    n -> data = data;
    n -> link = n;

    return n;
}

// displaying function
void display(node n){
    printf("HEAD -> ");
    node temp = n;
    do{
        printf("%d -> ",temp -> data);
        temp = temp -> link;
    }while(temp !=  n);

    printf("NULL \n");
}

// insert in the front
node ins_in_front(node n, int data){
    // Creating the new_node !
    node new_node = create_node(data);

    if(new_node == NULL){
        printf("Node creation failed !");
    }
    node temp = n;
    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = new_node;
    new_node -> link = n;

    return new_node;
}

node ins_in_rear(node n, int data){
    node new_node = create_node(data);
    node temp = n;
    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = new_node;
    new_node -> link = n;

    return n;
}

node del_in_front(node n){
    node temp = n;

    
}

int main(void){
    node head = create_node(2);
    display(head);
    head = ins_in_front(head, 4);
    display(head);
    head = ins_in_rear(head, 8);
    display(head);
    
}