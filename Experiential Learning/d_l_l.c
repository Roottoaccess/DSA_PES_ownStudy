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
        printf("Memory not allocated !");
    }

    n -> data = data;
    n -> next = NULL;
    n -> prev = NULL;

    return n;
}

void display(node n){
    if(n == NULL){
        printf("No node present");
    }
    printf("Head -> ");

    while(n != NULL){
        printf("%d -> ",n -> data);
        n = n -> next;
    }
    printf("NULL \n");
}

node ins_in_front(node n, int data){
    node new_node = create_node(data);
    if(new_node == NULL){
        printf("There is a problem to creating the new node !");
    }
    new_node -> next = n;
    new_node -> prev = NULL;

    return new_node;
}

node ins_in_rare(node n, int data){
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

node delete_in_front(node n){
    node temp = n;
    n = n -> next;
    free(temp);
    n -> prev = NULL;

    return n;
}

node delete_in_rare(node n){
    node temp = n;

    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    node demo = temp -> next;

    demo -> prev -> next = NULL;

    free(demo);

    // printf("%d\n", demo -> data);
    return n;
}

node ins_at_position(node n, int data, int pos){
    node new_node = create_node(data);

    node temp = n;

    if(pos == 0){
        new_node -> next = n;
        new_node -> prev = NULL;

        return new_node;
    }

    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }

    new_node -> next = temp->next;
    temp->next = new_node;
    new_node -> prev = temp;
    temp -> next -> prev = new_node;

    return n;
}

node delete_pos(node n, int pos){
    node temp = n;

    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }

    // node demo = temp -> next;
    // free(demo);

    temp -> next = temp -> next -> prev; // complete tommorow !!!!
    temp -> prev = temp -> prev -> next; // need to sleep rn :(

    free(temp);

    return n;
}

int main(void){
    node n = create_node(22);
    display(n);
    n = ins_in_front(n, 20);
    display(n);
    n = ins_in_rare(n , 44);
    display(n);
    // n = delete_in_front(n);
    // display(n);
    n = delete_in_rare(n);
    display(n);
    n = ins_at_position(n, 4, 1);
    display(n);
    n = delete_pos(n, 1);
    display(n);
}