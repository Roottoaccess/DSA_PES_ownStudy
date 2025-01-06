// This is a program to perform the singly link list in C programming
#include<stdio.h>
#include<stdlib.h>

// creating the structure
typedef struct node{
    int data;
    struct node *link;
}*node;

// creating the node
node create_node(int data){
    // dynamic memory allocation

    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    n -> data = data;
    n -> link = NULL;

    return n;
}

// inserting the node in the front
node ins_in_front(node n, int data){
    // creating the new node !
    node new_node = create_node(data);

    new_node -> link = n;

    return new_node;
}

// insert the node in the rare
node ins_in_rare(node n, int data){

    // creating the new node
    node new_node = create_node(data);
    node temp = n;
    while(temp -> link != NULL){
        temp = temp -> link;
    }

    temp -> link = new_node;

    return n;
}

// delete the node from thw front
node delete_front(node n){
    if(n == NULL){
        printf("There is no node present in the memory to delete !");
    }
    node temp = n;

    n = n -> link;

    free(temp);

    return n;
}

// delete the node from the rare
node delete_rare(node n){
    node temp = n;

    while(temp -> link -> link != NULL){
        temp = temp -> link;
    }
    // printf("%d\n", temp -> data);
    // return 0;
    node to_delete = temp-> link;
    temp -> link = NULL;
    free(to_delete);
    return n;
}

// insert in the position
node ins_in_position(node n,int data, int pos){
    if(n == NULL){
        printf("There is no node present in the memory");
    }

    if(pos == 0){
        // insert in the first
        return ins_in_front(n, data);
    }
    node new_node = create_node(data);
    node temp = n;
    for(int i = 0; i < pos -1; i++){
        temp = temp -> link;
    }
    if(temp -> link == NULL){
        return ins_in_rare(n, data);
    }
    // checking for the last position condition....
    new_node -> link = temp -> link;
    temp -> link = new_node;


    return n;
}

// delete in the position function
node delete_in_pos(node n, int pos){
    if(pos == 0){
        return delete_front(n);
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    // checking for the last node..
    if(temp -> link == NULL){
        return delete_rare(n);
    }

    node demo = temp -> link;

    temp -> link = temp -> link -> link;

    free(demo);

    return n;
}
// sorting the list
node sorting_list(node n){
    // applying the bubble sorting technique
    for(node i = n; i != NULL; i = i -> link){
        for(node j = n; j -> link != NULL; j = j -> link){
            if(j -> data > j -> link -> data){
                int store = j -> data;
                j -> data = j -> link -> data;
                j -> link -> data = store;
            }
        }
    }

    return n;
}

// reversing the singly link_list
node reverse(node n){
    // creating an empty new list
    node rev_list = NULL;

    while(n != NULL){
        int data = n -> data;
        n = delete_front(n);

        rev_list = ins_in_front(rev_list, data);
    }

    return rev_list;
}

// displaying the link
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory to display");
    }

    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ",n -> data);
        n = n -> link;
    }

    printf("NULL \n");
}

// insert in the front funtion

// Creating the main function for calling the functions
int main(void){

    node head = create_node(2);
    head = ins_in_front(head, 4);
    head = ins_in_rare(head, 6);
    display(head);
    // head = delete_front(head);
    // display(head);
    // head = delete_rare(head);
    // display(head);
    head = ins_in_position(head, 22, 2);
    display(head);

    // head = delete_in_pos(head, 4);
    // display(head);

    head = sorting_list(head);
    display(head);

    head = reverse(head);
    display(head);
}
