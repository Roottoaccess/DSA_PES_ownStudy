// Link list program by me understanding
// importing the libraries
#include<stdio.h>
#include<stdlib.h>

// creating the structure
typedef struct node {
    int data;
    struct node *link;
}*node;

// creating the funtion
node create_function(){
    // allocating the memory dynamically

    node n = (node) malloc (sizeof(node));

    // checking the memory allocation is successed or not ?
    if(n == NULL){
        printf("Memory allocation failed !");
    } // 
    int data; printf("What's the data? "); scanf("%d",&n->data);

    n->link = NULL;

    return n;
}

// Displaying the first node
void display(node n){
    printf("HEAD -> ");
    while(n != NULL){
        printf("%d -> ",n->data);

        n = n -> link;
    }
    printf("NULL \n");
}

// Inserting in front
node ins_front(node n){
    node new_node = create_function();

    if(new_node == NULL){
        return n;
    }
    new_node -> link = n;

    return new_node;
}

// Inserting in the last
node ins_last(node n){
    node new_node = create_function();
    node temp = n;
    while(temp->link != NULL){
        temp = temp -> link;
    }
    // new_node = temp -> link;
    temp -> link = new_node;
    return n;
}

// Insert at position
node ins_at_position(node n){
    node new_node = create_function();

    int pos; printf("What's the position? ");
    scanf("%d",&pos);
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    new_node -> link = temp -> link;
    temp -> link = new_node;

    return n;
}

// Delete from front
node delete_front(node n){
    if(n == NULL){
        printf("There is no node present in the memory..\n");
    }
    node temp = n;
    n = n -> link;

    free(temp);
    return n;
}

// Delete from the last
node delete_last(node n){
    if(n == NULL){
        return NULL;
    }
    node temp = n;

    while(temp -> link -> link != NULL){
        temp = temp -> link;
    }
    node p = temp -> link;
    temp -> link = NULL;

    free(p);

    return n;
}
// delete at position
node delete_at_position(node n){
    if(n == NULL){
        printf("There is no node present in the memory !");
    }

    int pos; printf("Enter the position to delete? ");
    scanf("%d",&pos);
    node temp = n;
    if(pos == 0){
        return delete_front(n);
    }
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }
    node p = temp -> link;
    temp -> link = temp -> link -> link;
    free(p);
    return n;
}

int main(void){
    // calling the functions one by one
    node n = create_function();
    display(n);
    n = ins_front(n);
    display(n);
    n = ins_last(n);
    display(n);
    n = ins_at_position(n);
    display(n);
    // n = delete_front(n);
    // display(n);
    // n = delete_last(n);
    // display(n);
    n = delete_at_position(n);
    display(n);
}