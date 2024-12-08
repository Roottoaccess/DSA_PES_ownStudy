#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*node;

// creaing the node
node creating_node(int data){
    // dynamic memory
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    n -> data = data;
    n -> link = n;

    return n;
}

// node go_last(node n){
//     node temp = n;

//     while(temp -> link != n){
//         temp = temp -> link;
//     }
//     return n;
// }

// insert at front
node insert_at_front(node n,int data){

    node new_node = creating_node(data);
    if (new_node == NULL) {
        return n;
    }

    if (n == NULL) { // Handle empty list
        new_node->link = new_node;
        return new_node;
    }

    node temp = n;
    while(temp -> link != n){
        temp = temp -> link;
    }

    temp -> link = new_node;
    new_node-> link = n;
    n = new_node;
    return n;
}

// display function
void display(node n){
    printf("HEAD -> ");
    node temp = n;
    while(temp != n){
        printf("%d -> ", temp -> data);
        temp = temp -> link;
    }
    printf("%d -> %d \n",temp -> data, temp -> link -> data);

    // printf("HEAD \n");
    /*
        do{
            printf("%d -> ", temp -> data);
            temp = temp -> link;
        }while(temp != n);

        printf("%d -> %d \n",temp -> data, temp -> link -> data);
    */
}

int main(void){
    node head = creating_node(2);
    display(head);
    head = insert_at_front(head, 4);
    display(head);
    head = insert_at_front(head, 6);
    display(head);
    head = insert_at_front(head, 8);
    display(head);

    return 0;
}