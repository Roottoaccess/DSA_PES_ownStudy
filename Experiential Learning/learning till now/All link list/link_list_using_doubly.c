// creating the doubly link list
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

// inserting in the front
node ins_in_front(node n, int data){
    // creating the new node
    node new_node = create_node(data);
    if (new_node == NULL) {
        return n;  // Return the list as is if memory allocation fails
    }

    if(n != NULL){
        n -> prev = new_node;
    }
    new_node -> next = n;
    new_node -> prev = NULL;

    return new_node;
}

// inserting in the rear
node ins_in_rear(node n, int data){
    node new_node = create_node(data);

    node temp = n;

    while(temp -> next != NULL){
        temp = temp -> next;
    }

    temp -> next = new_node;
    new_node -> prev = temp;
    new_node -> next = NULL;
    return n;
}

// delete from the front
node del_in_front(node n){
    node temp = n;

    n = n -> next;

    n -> prev = NULL;

    free(temp);

    return n;
}
// delete from the rear
node del_in_rear(node n){
    node temp = n;

    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }

    node demo = temp -> next;

    temp -> next = NULL;

    free(demo);

    return n;
}

// insert in the position
node ins_in_pos(node n, int data, int pos){
    node new_node = create_node(data);

    // if(pos == 0){
    //     return ins_in_front(n, data);
    // }
    node temp = n;
    // for(int i = 0;i < pos;i++){
    //     if (temp == NULL) {
    //         return n;  // Position out of bounds
    //     }
    //     temp = temp -> next;
    // }
    int actual_position = 0;
    while(temp != NULL){
        if(pos == 0){
            return ins_in_front(n,data);
        }

        if(pos == actual_position){
            break;
        }
        actual_position++;
        temp = temp -> next;
    }
    new_node -> prev = temp -> prev;
    new_node -> next = temp;
    temp -> prev = new_node;
    temp -> prev -> next = new_node;
    // if(temp -> next == NULL){
    //     return ins_in_rear(n, data);
    // }
    // new_node -> next = temp -> next;
    // if(temp -> next != NULL){
    //     temp -> next -> prev = new_node;
    // }
    // temp -> next = new_node;
    // new_node -> prev = temp;

    return n;
}

// delete in the position
node del_in_pos(node n, int pos){
    if(pos == 0){
        return del_in_front(n);
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }
    if(temp -> next == NULL){
        return del_in_rear(n);
    }

    // printf("%d\n", temp -> data);
    // return 0;

    node demo = temp -> next;
    temp -> next = demo -> next;
    free(demo);
    return n;
}

void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory to display !");
    }

    printf("HEAD <-> ");
    while(n != NULL){
        printf("%d <-> ",n -> data);
        n = n -> next;
    }
    printf("NULL \n");
}

int main(void){
    node head = create_node(2);
    display(head);
    head = ins_in_front(head, 4);
    display(head);
    head = ins_in_rear(head, 8);
    display(head);
    // head = del_in_front(head);
    // display(head);
    // head = del_in_rear(head);
    // display(head);
    head = ins_in_pos(head, 5, 2);
    display(head);
    // head = del_in_pos(head, 2);
    // display(head);
}