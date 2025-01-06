// implementing the queue using the link list
// Applying the FIFO operation

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}*node;

// creating the node....
node create_node(int data){
    node n = (node) malloc (sizeof(node));

    if(n == NULL){
        printf("Memory allocation fialed !\n");
    }

    n -> data = data;
    n -> link = NULL;

    return n;
}

// creating Enqueue Operation....
node enqueue(node n, int data){
    // creating the new node
    node new_node = create_node(data);

    node temp = n;

    while(temp -> link != NULL){
        temp = temp -> link;
    }

    temp -> link = new_node;
    return n;
}

// performing the deque operation in the queue
node deque(node n){
    if(n == NULL){
        printf("There is no element found in the queue !\n");
    }
    node temp = n;

    n = n -> link;

    free(temp);

    return n;
}


// creating the display function to display the queue
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory to display !\n");
    }

    printf("FRONT -> ");
    // node temp = n;
    while(n != NULL){
        printf("| %d | ", n -> data);
        n = n -> link;
    }
    printf("-> REAR \n");
}

// Creating the PEEK operation for the queue
void peek(node n){
    if(n == NULL){
        printf("There is no element present in the memory !\n");
    }else{
        printf("PEEK -> | %d |\n", n -> data);
    }
}

int main(void){
    node rear = create_node(2);
    rear = enqueue(rear, 4);
    rear = enqueue(rear, 8);
    display(rear);
    rear = deque(rear);
    display(rear);
    rear = enqueue(rear, 18);
    display(rear);
    peek(rear);
}