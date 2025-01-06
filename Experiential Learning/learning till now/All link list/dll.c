#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}*node;

// create node function
node create_node(int data){
    // dynamic memory allocation
    node head = (node) malloc (sizeof(struct node));

    if(head == NULL){
        printf("Node is not created !");
    }

    head -> data = data;
    head -> next = NULL;
    head -> prev = NULL;

    return head;
}

node ins_in_front(node head, int data){
    node new_node = create_node(data);

    if(new_node == NULL){
        printf("Node creation failed !");
    }

    new_node -> next = head;
    head -> prev = new_node;
    new_node -> prev = NULL;

    return new_node;
}

node ins_in_rear(node head, int data){
    node new_node = create_node(data);

    node temp = head;

    while(temp -> next != NULL){
        temp = temp -> next;
    }
    // printf("%d \n", temp -> data);
    // return 0;

    temp -> next = new_node;
    new_node -> prev = temp;

    return head;
}

node ins_in_pos(node head, int data, int pos){
    node new_node = create_node(data);

    if(pos == 0){
        return ins_in_front(head, data);
    }
    node temp = head;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }
    if(temp -> next == NULL){
        return ins_in_rear(head, data);
    }

    new_node -> next = temp -> next;
    temp -> next -> prev = new_node;
    temp -> next = new_node;
    new_node -> prev = temp;

    return head;
}

// deleting in the front
node delete_in_front(node head){
    node temp = head;

    head = head -> next;

    free(temp);

    return head;
}

// delete in the rear
node delete_in_rear(node head){
    node temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    node demo = temp;

    demo -> prev -> next = NULL;

    free(demo);

    return head;

    // printf("%d \n", demo -> data);
    // return 0;
}

node delete_in_pos(node head, int pos){
    if(pos == 0){
        return delete_in_front(head);
    }
    node temp = head;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }
    if(temp == NULL || temp -> next == NULL){
        return delete_in_rear(head);
    }

    node demo = temp -> next;

    temp -> next = temp -> next -> next;
    if(temp -> next != NULL){
        temp -> next -> prev = temp;
    }
    free(demo);
    return head;

    // printf("%d \n", temp -> data);
    // return 0;
}

// display function
void display(node head){
    if(head == NULL){
        printf("There is no node present in the memory to display !");
    }
    printf("HEAD <-> ");
    while(head != NULL){
        printf("%d <-> ",head -> data);
        head = head -> next;
    }
    printf("NULL \n");
}

// creating the main function
int main(void){
    node head = create_node(2);
    display(head);
    head = ins_in_front(head, 4);
    display(head);
    head = ins_in_rear(head, 10);
    display(head);
    head = ins_in_pos(head, 12, 0);
    display(head);
    head = delete_in_front(head);
    display(head);
    head = delete_in_rear(head);
    display(head);
    // head = delete_in_pos(head, 3);
    // display(head);
    return 0;
}