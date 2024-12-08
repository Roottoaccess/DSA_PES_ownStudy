// Creating the doubly link list
#include<stdio.h>
#include<stdlib.h>

// creating the structure
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}*node;

// creating the node function
node createnode(int data){
    // dynamic memory allocation
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memeory allocation failed");
    }

    n -> data = data;
    n -> next = NULL;
    n -> prev = NULL;

    return n;
}

// insert in the front....
node ins_in_front(node n, int data){
    // creating the new node
    node new_node = createnode(data);
    if(new_node == NULL){
        printf("Error to create the new node !");
        return NULL;
    }

    new_node -> next = n;
    new_node -> prev = NULL;

    // make it inside the condition
    // if(n != NULL){
    //     n -> prev = new_node;
    // }

    return new_node;
}

// insert in the rare....
node ins_in_rare(node n, int data){
    // creating the new node
    node new_node = createnode(data);

    if(new_node == NULL){
        return NULL;
    }

    node temp = n;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    // printf("%d \n",temp -> data);

    // return 0;

    temp -> next = new_node;
    new_node -> prev = temp;
    new_node -> next = NULL;

    return n;
}

// insert in position....
node ins_in_pos(node n, int data, int pos){
    // creating the new node
    node new_node = createnode(data);

    // checking for the first position
    if(pos == 0){
        new_node -> next = n;

        new_node -> prev = NULL;

        if(n != NULL){
            n -> prev = new_node;
        }

        return new_node;
    }

    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }

    new_node -> next = temp -> next;
    temp -> next = new_node;
    new_node -> prev = temp;
    temp -> next -> prev = new_node;

    return n;
}

node delete_front(node n){
    if(n == NULL){
        printf("There is no node present in the memory to delete or free !!");
        return NULL;
    }

    node temp = n;

    n = n -> next;
    free(temp);

    n -> prev = NULL;

    return n;
}

node delete_last(node n){
    node temp = n;

    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }

    // printf("%d \n", temp -> data);

    // return 0;

    node demo = temp -> next;

    free(demo);

    temp -> next = NULL;

    return n;
}

// node delete_in_position(node n, int pos){

//     if(pos == 0){
//         node temp = n;

//         n = n -> next;
//         free(temp);

//         n -> prev = NULL;

//         return n;
//     }

//     node temp = n;

//     for(int i = 0; i < pos - 1; i++){
//         temp = temp -> next;
//     }

//     // printf("%d \n", temp -> data);

//     // return 0;

//     node demo = temp -> next;

//     free(demo);

//     temp -> next = temp -> next -> prev;
//     temp -> next -> prev = temp;

//     return n;
// }

node delete_in_position(node n, int pos) {
    if (n == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    if (pos == 0) {
        // Deleting the head node.
        node temp = n;
        n = n->next;
        free(temp);

        if (n != NULL) {
            n->prev = NULL; // Update the new head's previous pointer.
        }

        return n;
    }

    node temp = n;

    // Traverse to the node before the position to delete.
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range.\n");
            return n; // Return the unchanged list.
        }
        temp = temp->next;
    }

    node to_delete = temp->next;

    if (to_delete == NULL) {
        printf("Position out of range.\n");
        return n; // Return the unchanged list.
    }

    // Update links to bypass the node to delete.
    temp->next = to_delete->next;

    if (to_delete->next != NULL) {
        to_delete->next->prev = temp;
    }

    free(to_delete); // Free the memory of the node to delete.

    return n;
}


// displaying the node
void display(node n){
    printf("HEAD -> ");
    while(n != NULL){
        printf(" %d -> ", n -> data);
        n = n -> next;
    }
    printf("NULL \n");
}

int main(void){
    node head = createnode(22);
    display(head);

    head = ins_in_front(head , 33);
    display(head);

    head = ins_in_rare(head, 44);
    display(head);

    head = ins_in_pos(head, 25, 2);
    display(head);

    // head = delete_front(head);
    // display(head);

    // head = delete_last(head);
    // display(head);

    head = delete_in_position(head, 2);
    display(head);
    return 0;
}