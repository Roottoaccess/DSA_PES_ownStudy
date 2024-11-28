#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*node;

node create_node(){
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed");
    }

    int data; printf("Enter the data? "); scanf("%d",&n->data);
    n -> link = NULL;

    return n;
}

node ins_at_front(node n){
    node new_node = create_node();

    if(new_node == NULL){
        printf("Node is not created successfully !");
    }

    new_node -> link = n;
    return new_node;
}

node ins_at_last(node n){
    node new_node = create_node();
    node temp = n;
    while(temp -> link != NULL){
        temp = temp -> link;
    }
    temp -> link = new_node;

    return n;
}

node ins_at_pos(node n){
    node new_node = create_node();

    int pos; printf("Enter the position? "); scanf("%d",&pos);
    if(pos == 0){
        return ins_at_front(n);
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    new_node -> link = temp -> link;
    temp -> link = new_node;

    return n;
}

node delete_front(node n){
    if(n == NULL){
        printf("There is no node present in the memory to delete");
    }
    node temp = n;
    n = n -> link;

    free(temp);
    return n;
}

node delete_rare(node n){
    if(n == NULL){
        printf("There is no node present in the memory to delete");
    }
    node temp = n;

    while(temp -> link -> link != NULL){
        temp = temp -> link;
    }

    node p = temp -> link;

    temp -> link = NULL;

    free(p);

    return n;
}

node delete_pos(node n){
    if(n == NULL){
        printf("There is no node present in the memory to delete");
    }
    node temp = n;
    int pos; printf("Enter the position to delete? "); scanf("%d",&pos);

    if(pos == 0){
        return delete_front(n);
    }
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    node q = temp -> link;
    free(q);
    temp -> link = temp -> link -> link;

    return n;
}

void display(node n){
    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ", n -> data);
        n = n -> link;
    }
    printf("NULL \n");
}

int main(void){
    node n = create_node();
    display(n);
    n = ins_at_front(n);
    display(n);
    n = ins_at_last(n);
    display(n);
    n = ins_at_pos(n);
    display(n);
    n = delete_front(n);
    display(n);
    n = delete_rare(n);
    display(n);
    n = delete_pos(n);
    display(n);
}