// This is the circular link list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*node;

// creating the create_node function
node create_node(int data){
    node n = (node) malloc (sizeof(struct node));

    if(n == NULL){
        printf("Memory allocaion failed !");
    }

    n -> data = data;
    n -> link = n;

    return n;
}

// creating the insert_in_front function
node ins_in_front(node n, int data){
    if(n == NULL){
        return create_node(data);
    }

    node new_node = create_node(data);

    if(new_node == NULL){
        printf("New node creation failed !");
    }
    
    node temp = n;
    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = new_node;
    new_node -> link = n;

    return new_node;
}
// creating the ins_in_last function
node ins_in_rear(node n, int data){
    // creating the new node
    node new_node = create_node(data);

    if(new_node == NULL){
        printf("The new_node is not been created !");
    }
    node temp = n;
    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = new_node;
    new_node -> link = n;

    return n;
}

// delete in the front
node del_in_front(node n){
    if(n -> link == n){
        free(n);
        return NULL;
    }
    node temp = n;
    node demo = n;

    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = demo -> link;

    free(demo);

    return n;
}

// creating the display function
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
    }
    node temp = n;
    printf("HEAD <-> ");
    do{
        printf("%d <-> ", temp -> data);
        temp = temp -> link;
    }while(temp != n);

    printf("NULL \n");
}

// creating the main function ->
int main(void){
    node head = create_node(2);
    display(head);
    head = ins_in_front(head, 4);
    display(head);
    head = ins_in_rear(head, 8);
    display(head);
    head = del_in_front(head);
    display(head);
}