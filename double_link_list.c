#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}*node;

node create_node(int data){
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    n -> data = data;
    n -> next = NULL;
    n -> prev = NULL;
    return n;
}

void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
    }

    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ",n -> data);

        n = n -> next;
    }
    printf("NULL \n");
}

node insert_node_front(node n, int data){
    // creating the node
    node new_node = create_node(data);

    if(new_node == NULL){
        printf("Node creating failed !");
    }
    // node temp = n;
    new_node -> next = n;
    new_node -> prev = NULL;

    return new_node; 
}

node insert_node_last(node n, int data){
    // creating the node
    node new_node = create_node(data);

    if(new_node == NULL){
        printf("Node creating failed !");
    }

    node temp = n;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = new_node;
    new_node -> prev = temp;
    new_node -> next = NULL;
    return n;
}

node delete_from_front(node n){
    if(n == NULL){
        printf("There is no node present in the memory");
    } 

    node temp = n;

    n = n -> next;
    n -> prev = NULL;
    free(temp);

    return n;
}

node delete_at_last(node n){
    if(n == NULL){
        printf("There is no node present in the memory");
    }
    node temp = n;

    while(temp -> next != NULL){
        temp = temp -> next;
    }
    // temp -> prev -> next = NULL;
    // free(temp);

    if(temp -> prev == NULL){
        free(temp);
        return NULL;
    }
    temp -> prev -> next = NULL;

    free(temp);

    // node p = temp -> next;

    // free(p);

    // temp -> prev = NULL;

    return n;
}

node ins_in_pos(node n, int data, int pos){
    if(n == NULL){
        printf("There is no node present in the memory");
    }

    // creating the node
    node new_node = create_node(data);
    if(pos == 0){
        new_node -> next = n;
        new_node -> prev = NULL;

        return new_node;
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;

    return n;
}

node delete_in_pos(node n, int pos) {
    if (n == NULL) {
        printf("There is no node present to delete\n");
        return NULL;
    }

    node temp = n;

    // Edge case: deleting the head node
    if (pos == 1) {
        n = n->next; // Move head to the next node
        if (n != NULL) {
            n->prev = NULL; // Update the new head's previous pointer
        }
        free(temp); // Free the old head node
        return n;
    }

    // Traverse to the node at position pos - 1
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position\n");
            return n;
        }
        temp = temp->next;
    }

    node to_delete = temp->next;

    if (to_delete == NULL) {
        printf("Invalid position\n");
        return n;
    }

    // Update pointers to bypass the node to delete
    temp->next = to_delete->next;
    if (to_delete->next != NULL) {
        to_delete->next->prev = temp;
    }

    free(to_delete); // Free the node

    return n;
}


int main(void){
    node n = create_node(2);
    display(n);

    n = insert_node_front(n, 33);
    display(n);

    // n = delete_from_front(n);
    // display(n);

    n = insert_node_last(n, 55);
    display(n);


    n = ins_in_pos(n, 88, 2);
    display(n);
    n = delete_at_last(n);
    display(n);

    // n = delete_in_pos(n, 2);
    // display(n);
}