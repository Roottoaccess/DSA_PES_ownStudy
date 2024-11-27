#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*node;

// creating the node
node create_node(){
    // create the memory dynamically
    node n = (node)malloc(sizeof(node));
    if(n == NULL){
        printf("Memory allocation failed !");
    }

    int data; printf("Enter data: "); scanf("%d",&n->data);

    n->link = NULL;

    return n;
}

// display function
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
    }
    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ",n->data);
        n = n -> link;
    }
    printf("NULL \n");
}

// ins_at_first
node ins_at_first(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
    }
    // creating the new_node
    node new_node = create_node();

    new_node -> link = n;
    return new_node;
}

// ins_at_last
node ins_at_last(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
    }
    node new_node = create_node();
    node temp = n;
    while(temp -> link != NULL){
        temp = temp -> link;
    }

    temp -> link = new_node;

    return n;
}

// insert in position
node ins_at_position(node n){
    if(n == NULL){
        return NULL;
    }

    // creating the node
    node new_node = create_node();

    int pos; printf("Enter the position: "); scanf("%d",&pos);
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    create_node
}

int main(void){
    node n = create_node();
    display(n);

    n = ins_at_first(n);
    display(n);

    n = ins_at_last(n);
    display(n);
}