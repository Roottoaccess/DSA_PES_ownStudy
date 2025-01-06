// This is the program for the circular link list
#include<stdio.h>
#include<stdlib.h>

// creating the structure
typedef struct node{
    int data;
    struct node *link;
}*node;

// creating the node function
node create_node(int data){
    // dynamic memory allocation
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    n -> data = data;
    n -> link = n; // n -> link is connected to the head means n itself..
    return n;
}

// displaying the node function
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
    }
    node temp = n;
    printf("Head -> ");
    do{
        printf("%d -> ", temp -> data);
        temp = temp -> link;
    }while(temp != n);

    printf("NULL \n");
}

// inserting in the front node
node ins_in_front(node n, int data){
    // creating a new node
    node new_node = create_node(data);

    if(new_node == NULL){
        printf("New node didn't created !");
    }
    node temp = n;
    do{
        temp = temp -> link;
    }while(temp != n);

    temp -> link = new_node;
    new_node -> link = n;

    return new_node;
}

// insert in the last node
node ins_in_last(node n, int data){
    // creating the new node
    node new_node = create_node(data);

    if(new_node == NULL){
        printf("New node didn't created !");
    }
    // node hold_head = n;
    node temp = n;
    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = new_node;
    new_node -> link = n;

    // printf("%d\n", temp -> data);

    // return 0;
    return n;
}

// deleting from the front
node delete_front(node n){
    if(n == NULL){
        printf("There is no node present in the memory to delete !");
    }

    node temp = n;
    node ptr = n;

    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = ptr -> link;
    n = ptr -> link;

    free(ptr);

    return n;
}

// delete in the rare
node delete_rare(node n){
    node temp = n;
    do{
        temp = temp -> link;
    }while(temp -> link -> link != n);

    node last_position = temp -> link;

    temp -> link = n;

    free(last_position);

    return n;
}

// insert in position
node ins_in_position(node n, int data, int pos){
    node new_node = create_node(data);

     if (n == NULL && pos != 0) {
        printf("Error: Invalid position for an empty list.\n");
        return NULL;
    }

    if(pos == 0){
        //     node temp = n;
        // do{
        //     temp = temp -> link;
        // }while(temp != n);

        // temp -> link = new_node;
        // new_node -> link = n;

        // return new_node;
        return ins_in_front(n, data);
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    if(temp -> link == n){
        temp -> link = new_node;
        new_node -> link = n;
        return n;
    }
    
    new_node -> link = temp -> link;
    temp -> link = new_node;

    return n;
}

// delete in the position(for tommorow ----> )
// node delete_in_position(node n, int pos) 
// {
//     if(pos == 0){
//         return delete_front(n);
//     }

//     node temp = n;

//     for(int i = 0; i < pos - 1; i++){
//         temp = temp -> link;
//     }

//     if(temp -> link == n){
        
//     }
// }

// creating the main function
int main(void){
    node n = create_node(22);
    display(n);
    n = ins_in_front(n, 33);
    display(n);
    n = ins_in_last(n, 44);
    display(n);
    // n = delete_front(n);
    // display(n);
    // n = delete_rare(n);
    // display(n);

    n = ins_in_position(n, 28, 2); // Problem when I am giving the position 0
    display(n);
}