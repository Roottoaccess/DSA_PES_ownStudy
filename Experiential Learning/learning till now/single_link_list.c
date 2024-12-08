#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*node;

// creating the node
node create_node(int data){
    // dynamic memory allocation
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Dynamic memory allocation failed !");
    }

    n -> data = data;
    n -> link = NULL;

    return n;
}

// creating the display function
void display(node n){
    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ",n -> data);
        n = n -> link;
    }
    printf("NULL \n");
}

// inserting node in the front
node insert_node_front(node n, int data){
    // creating the new node for inserting
    node new_node = create_node(data);

    new_node -> link = n;

    return new_node;
}

// inserting node in the last
node ins_in_last(node n, int data){
    // creating the new node
    node new_node = create_node(data);
    node temp = n;
    while(temp -> link != NULL){
        temp = temp -> link;
    }

    // printf("%d", temp -> data);
    // return 0;

    temp -> link = new_node;

    return n;
}

// insert node in the position given by the user
node ins_in_position(node n, int data, int pos){
    // creating the node
    node new_node = create_node(data);

    // checking for the first condition
    if(pos == 0){
        new_node -> link = n;
        return new_node;
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }

    // printf("%d", temp -> data);
    // return 0;

    new_node -> link = temp -> link;
    temp -> link = new_node;

    return n;
}

// delete the first node
node delete_first(node n){
    if(n == NULL){
        printf("There is no node present to delete in the memory..");
    }

    node temp = n;
    n = n -> link;
    free(temp);

    return n;
}

// delete the last node
node delete_last(node n){

    if(n -> link == NULL){
        free(n);
        return NULL;
    }

    node temp = n;

    while(temp -> link -> link != NULL){
        temp = temp -> link;
    }

    // printf("%d\n", temp -> data);
    // return 0;

    node p = temp -> link;
    free(p);
    temp -> link = NULL;
    return n;
}

node delete_at_position(node n, int pos){
    // deleting for the first position
    if(pos == 0){
        node temp = n;
        n = n -> link;
        free(temp);

        return n;
    }
    node temp = n;
    // traversion the position.....
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }

    // printf("%d\n", temp -> data);
    // return 0;

    node demo = temp -> link;
    temp -> link = temp -> link -> link;
    free(demo);
    return n;
}

// sorting the link list
node sorting(node n){
    if(n == NULL){
        printf("Sorting not posible because there is no node present in the memory");
    }
    else if(n -> link == NULL){
        return n;
    }
    node temp = n;
    // while(temp -> link != NULL){
    //     temp = temp -> link;
    // }
    // printf("%d \n", temp -> data);
    // return 0;
    for(node i = n; i != NULL; i = i -> link){
        for(node j = n; j -> link != NULL; j = j -> link){
            if(j -> data > j -> link -> data){
                int demo = j -> data;
                j -> data = j -> link -> data;
                j -> link -> data = demo;
            }
        }
    }

    return n;
}

// reversing the link list
node reverse(node n){

    // creating another empty link list
    node rev_list = NULL;
    // node temp = n;
    while(n != NULL){
        int data = n -> data;
        n = delete_first(n);
        rev_list = insert_node_front(rev_list , data);
    }
    return rev_list;
}

// creating the main function to display
int main(void){

    node head = create_node(22);
    display(head);
    head = insert_node_front(head, 33);
    display(head);
    head = ins_in_last(head, 44);
    display(head);
    head = ins_in_position(head, 25, 0);
    display(head);
    // head = delete_first(head);
    // display(head);
    // head = delete_last(head);
    // display(head);
    // head = delete_at_position(head, 2);
    // display(head);

    head = sorting(head);
    display(head);

    head = reverse(head);
    display(head);
    return 0;
}