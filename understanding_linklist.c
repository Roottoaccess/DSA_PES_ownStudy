#include<stdio.h>
#include<stdlib.h>
// creating the structure
typedef struct node{
    int data;
    struct node *link;
}*node;

// creating the node
node create_node(){
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    int data; printf("Enter the data: "); scanf("%d",&n->data);

    n -> link = NULL;

    return n;
}

// void display function
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
        // return NULL;
    }
    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ",n->data);

        n = n -> link;
    }
    printf("NULL \n");
}

// insert in front function()
node inst_in_front(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
        // return NULL;
    }
    node new_node = create_node();

    new_node -> link = n;

    return new_node;
}

// insert in last
node inst_in_last(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
        // return NULL;
    }

    node new_node = create_node();

    node temp = n;
    while(temp -> link != NULL){
        temp = temp -> link;
    }

    temp -> link = new_node;

    return n;
}

// insert in position
node inst_in_pos(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
        // return NULL;
    }
    node new_node = create_node();

    int pos; printf("Enter the position: "); scanf("%d",&pos);
    node temp = n;
    if(pos == 0){
        new_node-> link = n;
        return new_node;
    }
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }

    new_node -> link = temp -> link;
    temp -> link = new_node;

    return n;
}

// delete in front
node delete_front(node n){
    if(n == NULL){
        printf("There is no node present to delete....");
    }
    node temp = n;

    n = n -> link;

    free(temp);
    return n;
}

// delete in rare
node delete_rare(node n){
    if(n == NULL){
        printf("There is no node present to delete....");
    }
    node temp = n;

    while(temp -> link -> link != NULL){
        temp = temp -> link;
    }

    node p = temp -> link;

    temp -> link= NULL;

    free(p);

    return n;
}

// delete in position
node delete_position(node n){
    if(n == NULL){
        printf("There is no node present to delete....");
    }

    node temp = n;
    int pos; printf("Enter the position to delete: "); scanf("%d",&pos);
    if(pos == 0){
            return delete_front(n);
        }
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }

    node q = temp -> link;

    temp -> link = temp -> link -> link;

    free(q);

    return n;
}

int main(void){

    // calling the functions
    node n = create_node();
    display(n);
    n = inst_in_front(n);
    display(n);
    n = inst_in_last(n);
    display(n);
    // n = inst_in_pos(n);
    // display(n);
    // n = delete_front(n);
    // display(n);
    // n = delete_rare(n);
    // display(n);
    n = delete_position(n);
    display(n);
}