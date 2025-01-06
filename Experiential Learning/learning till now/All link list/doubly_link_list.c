#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}*node;

// creating the node
node createnode(int data){

    // dynamic memory allocation
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    n -> data = data;
    n -> next = NULL;
    n -> prev = NULL;

    return n;
}

// insert the node in the front
node ins_in_front(node n, int data){
    // creating an new node
    node new_node = createnode(data);
    new_node -> next = n;
    // if(n != NULL){
    //     n -> prev = new_node;
    // }
    new_node -> prev = NULL;


    return new_node;
}

// insert the node in the rare
node ins_in_rare(node n, int data){
    node new_node = createnode(data);

    node temp = n;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = new_node;
    new_node -> prev = temp;

    return n;
}

// delete from the front
node delete_front(node n){
    if(n == NULL){
        printf("There is no node present in the memory to delete !");
    }

    node temp = n;
    n = temp -> next;

    if(temp -> next != NULL){
        temp -> next -> prev = NULL;
    }

    free(temp);

    return n;
}

// delete in the last
node delete_rare(node n){
    node temp = n;

    if(temp -> next == NULL){
        free(temp);
        return NULL;
    }
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    node demo = temp -> next;
    temp -> next = NULL;

    free(demo);

    // printf("%d\n", demo -> data);
    return n;
}

// insert in the position
node ins_in_position(node n, int data, int pos){
    // creating the node
    node new_node = createnode(data);

    if(pos == 0){
        new_node -> next = n;
        new_node -> prev = NULL;
        new_node = n;

        return n;
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }

    new_node -> next = temp -> next;
    temp -> next = new_node;
    temp -> next -> prev = new_node;
    new_node -> prev = temp;
    return n;
}

// delete in the position
node delete_node(node n, int pos){
    
}

// creating the display function
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory to display !");
    }

    printf("Head -> ");
    while(n != NULL){
        printf("%d -> ", n -> data);
        n = n -> next;
    }

    printf("NULL \n");
}

// main function for calling the function
int main(void){
    node head = createnode(2);
    display(head);
    head = ins_in_front(head, 4);
    display(head);
    head = ins_in_rare(head, 6);
    display(head);
    // head = delete_front(head);
    // display(head);
    // head = delete_rare(head);
    // display(head);

    head = ins_in_position(head, 8, 0);
    display(head);
}