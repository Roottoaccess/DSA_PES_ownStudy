#include<stdio.h>
#include<stdlib.h>

// creating the structure
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}*node;

// function for creating the node
node create_node(int data){
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

// creating the insert at first function
node ins_at_front(node n, int data){
    // creating a new node
    node new_node = create_node(data);

    new_node -> next = n;
    n -> prev = new_node;
    new_node -> prev = NULL;

    return new_node;
}

// creating the insert at last function
node ins_at_last(node n, int data){
    // creating a new node
    node new_node = create_node(data);

    node temp = n;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    // printf("%d",temp ->data);
    temp -> next = new_node;
    new_node -> prev = temp;
    new_node -> next = NULL;

    return n;
}

// insert in position
node ins_in_pos(node n, int data, int pos){
    // creating the new_node
    node new_node = create_node(data);

    node temp = n;
    // handling the edge case for inserting in the front (0) position
    if(pos == 0){
        new_node -> next = temp;
        temp -> prev = new_node;
        new_node -> prev = NULL;

        return new_node;
    }

    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }
    new_node -> next = temp -> next;
    temp -> next -> prev = new_node;
    temp -> next = new_node;
    new_node -> prev = temp;
    return n;
}


// creating the delete function to delete the node from front
node delete_front_node(node n){
    if(n == NULL){
        printf("Delete is not possible because there is no node present in the memory");
    }

    node demo = n;
    n = n -> next;
    if(n != NULL){
        n -> prev = NULL;
    }
    free(demo);

    return n;
}

// creating the delete function to delete node in the last
node delete_from_last(node n){
    // checking the condition if there is no node present in the memory
    if(n == NULL){
        return NULL;
    }
    node temp = n;
    while(temp -> next != NULL){
        temp = temp -> next; // going to the last node
    }
    if(temp -> prev == NULL){
        free(temp);
        return NULL;
    }
    temp -> prev -> next = NULL;
    free(temp);

    return n;
}


// creating the display function
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory to display !");
    }

    printf("HEAD -> ");

    while(n != NULL){
        printf("%d -> ", n -> data);

        n = n -> next;
    }

    printf("NULL \n");
}

int main(void){
    node n = create_node(2);
    display(n);
    n = ins_at_front(n, 1);
    display(n);
    n = ins_at_last(n , 22);
    display(n);
    n = ins_in_pos(n, 20, 1);
    display(n);
    // n = delete_front_node(n);
    // display(n);
    n = delete_from_last(n);
    display(n);
}