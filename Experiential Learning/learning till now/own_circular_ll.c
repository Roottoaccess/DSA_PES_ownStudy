// implementing the circulat link list program
#include<stdio.h>
#include<stdlib.h>

/* Creating the structure */
typedef struct node{
    int data;
    struct node *link;
}*node;

/* Creating the first node */
node create_node(int data){
    // dynamic memory allocation
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    n -> data = data;
    n -> link = n;

    return n;
}

/* Inserting the node in the front */
node ins_in_front(node n, int data){
    // creating a new node
    node new_node = create_node(data);

    if(new_node == NULL){
        printf("Failed to create the new node !");
    }
    // We have to traverse in the circular link list ->
    node temp = n;

    do{
        temp = temp -> link;
    }while(temp != n);

    temp -> link = new_node;
    new_node -> link = n;

    return new_node;
}

/* Inserting the node in rare */
node ins_in_rare(node n, int data){

    // creating the node
    node new_node = create_node(data);
    node temp = n;
    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = new_node;
    new_node -> link = n;

    return n;
}

/* deleting in the front */
node delete_front(node n){
    if(n == NULL){
        printf("There is no node in the memory to perform the delete operation !");
    }

    node temp = n;
    node hold = n;

    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = hold -> link;
    n = hold -> link;

    free(hold);

    return n;
}

/* delete in the last */
node delete_last(node n){
    node temp = n;

    do{
        temp = temp -> link;
    }while(temp -> link -> link != n);

    node hold_last = temp -> link;

    temp -> link = n;

    free(hold_last);

    return n;
}

/* insert in the position */
node insert_position(node n, int data, int pos){
    node new_node = create_node(data);
    if(pos == 0){
        node temp = n;
        do{
            temp = temp ->link;
        }while(temp -> link != n);

        temp -> link = new_node;
        new_node -> link = n;

        return new_node;
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    new_node -> link = temp -> link;
    temp -> link = new_node;

    if(temp -> link == n){
        temp -> link = new_node;
        new_node -> link = n;
        return n;
    }

    return n;
}

/* delete in position */
node delete_position(node n, int pos){
    if(pos == 0){
        return delete_front(n);
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    if(temp -> link == n){
        return delete_last(n);
    }
    node del_node = temp -> link;
    temp -> link = temp -> link -> link;
    free(del_node);
    return n;
}

/* Displaying the nodes */
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory to display !");
    }
    node temp = n;
    printf("HEAD -> ");
    do{
        printf("%d -> ", temp -> data);
        temp = temp -> link;
    }while(temp != n);

    printf("NULL \n");
}


// creating the main function to call the functions
int main(void){
    node head = create_node(2);
    display(head);
    head = ins_in_front(head, 1);
    display(head);
    head = ins_in_rare(head, 4);
    display(head);
    head = delete_front(head);
    display(head);
    head = delete_last(head);
    display(head);
    head = insert_position(head, 5, 2);
    display(head);
    head = delete_position(head, 1);
    display(head);
}
