// This is the link list practise program
#include<stdio.h>
#include<stdlib.h>

// creating the structure..
typedef struct node{
    int data;
    struct node *link;
}*node;

// create_node function
node create_node(int data){
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memeory allocation failed !");
    }

    n -> data = data;

    n -> link = NULL;

    return n;
}

// front, last, position, given/order

// void display
void display(node n){

    if(n == NULL){
        printf("There is no node present in the memory");
    }
    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ", n -> data);

        n = n -> link;
    }
    printf("NULL \n");
}

// ins_in_front
node ins_node(node n, int data){
    node new_node = create_node(data);

    if(new_node == NULL){
        return NULL;
    }

    new_node -> link = n;
    return new_node;
}

// ins_in_last
node ins_node_last(node n, int data){
    node new_node = create_node(data);

    if(new_node == NULL){
        return NULL;
    }
    node temp = n;
    while(temp -> link != NULL){
        temp = temp -> link;
    }

    temp -> link = new_node;

    return n;
}

// ins_in_pos
node ins_in_pos(node n, int data, int pos){
    node new_node = create_node(data);

    if(n == NULL){
        return NULL;
    }
    node temp = n;

    if(pos == 0){
        new_node -> link = n;
        return new_node;
    }
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }

    new_node -> link = temp -> link;
    temp -> link = new_node;

    return n;
}

// insert in order
node ins_in_order(node n, int data){

    node new_node = create_node(data);

    if(n == NULL){
        return n;
    }
    node temp = n;
    if(new_node -> data < n -> data){
        new_node -> link = n;

        return new_node;
    }
    else{
        while(temp -> link != NULL && temp -> link -> data < new_node -> data){
            temp = temp -> link;
        }

        new_node -> link = temp -> link;
        temp -> link = new_node;
    }
    return n;
}

node soritng_the_list(node n){
    if(n == NULL){
        printf("Sorting not possible because there is no node present in memory");
    }
    // node temp = n;
    for(node i = n; i != NULL; i = i -> link){
        for(node j = n; j -> link != NULL; j = j -> link){
            if(j -> data > j -> link -> data){
                // swapping
                int demo = j -> data;
                j -> data = j -> link -> data; 
                j -> link -> data = demo; 
            }
        }
    }

    return n;
}

node delete_front(node n){
    if(n == NULL){
        printf("There no node present in memory to delete");
    }

    node temp = n;

    n = n -> link;
    free(temp);

    return n;
}

node reverse_list(node n){
    if(n == NULL){
        printf("Reversing not possible because there is no node present here !");
    }
    node new_link_list = NULL;
    int data;
    while(n != NULL){
        data = n -> data;
        n = delete_front(n);
        new_link_list = ins_node(new_link_list, data);
    }
    return new_link_list;
}

node delete_the_given_node(node n, int data) {
    if (n->data == data)
    {
        return delete_front(n);       
    }
    node temp = n;
    while (temp->link->data != data)
    {
        temp = temp->link;
    }
    node remove = temp->link;
    temp->link = temp->link->link;
    free(remove);
    return n;
}

node merge_list(node n, node n2){
    node temp = n2;
    while (temp != NULL)
    {
        n = ins_node_last(n, temp->data);
        temp = temp->link;
    }
    return n;
}

int main(void){

    node n = create_node(2);
    // display(n);
    n = ins_node(n, 4);
    // display(n);
    n = ins_node_last(n, 6);
    // display(n);
    n = ins_in_pos(n, 8, 3);
    // display(n);
    n = soritng_the_list(n);
    // display(n);
    n = ins_in_order(n, 5);
    // display(n);
    // n = delete_front(n);
    // display(n);
    n = reverse_list(n);
    // display(n);
    n = delete_the_given_node(n, 6);
    display(n);

    node n2 = create_node(5);
    n2 = ins_node_last(n2, 3);
    n2 = ins_node_last(n2, 7);
    n2 = ins_node_last(n2, 2);
    n2 = ins_node_last(n2, 1);
    display(n2);

    n = merge_list(n, n2);
    display(n);


}