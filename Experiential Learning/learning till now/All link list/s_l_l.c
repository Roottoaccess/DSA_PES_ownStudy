// implementing stack using the link_list....
#include<stdio.h>
#include<stdlib.h>

// creating the structure of the stack implemetation
typedef struct node{
    int data;
    struct node *link;
}*node;

// creating the first node
node create_node(int data){
    // dynamic memory allocation
    node n = (node) malloc (sizeof(node));
    // checking the condition
    if(n == NULL){
        printf("Memory allcation failed !");
    }

    n -> data = data;
    n -> link = NULL;

    return n;
}

// Performing the push opeation!!
node push(node n, int data){
    // creating a new node
    node new_node = create_node(data);

    // connecting the node....
    new_node -> link = n;

    return new_node;
}
// Performing the pop operation!!
node pop(node n){
    if(n == NULL){
        printf("There is no data in the stack");
    }

    node temp = n;
    n = n -> link;
    free(temp);

    return n;
}

// Performing the peek operation
void peek(node n){
    printf("The Element in the PEEK -> %d \n",n->data);
}

// Total elements in the stack -->
void total_element(node n){
    // finding the total numbers of elements present in the stack !!
    // Checking the condition
    if(n == NULL){
        printf("There is no node present in the memory, so total element is 0\n");
    }
    node temp = n;
    int count = 1;

    while(temp -> link != NULL){
        count++;
        temp = temp -> link;
    }

    printf("The total elements in the Stack present -> %d\n", count);
}

// Deleting all the elements from the stack
void delete_all_ele(node n){
    node temp = n;
    while(temp -> link != NULL){
        temp = temp -> link;
        node demo = temp -> link;
        free(demo);
    }
    printf("Stack -> | %d | \n", temp -> data);
}

// creating the display function
void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory to display !");
    }

    printf("Top -> ");
    while(n != NULL){
        printf("| %d |", n -> data);
        n = n -> link;
    }
    printf("-> REAR \n");
}

// creating the main function for displaying all the methods
int main(void){
    // calling the nodes
    // node head = create_node(2);
    // display(head);
    // head = push(head, 4);
    // display(head);
    // head = push(head, 6);
    // display(head);
    // head = push(head, 8);
    // display(head);
    // head = pop(head);
    // display(head);
    // peek(head);
    // head = push(head, 12);
    // display(head);
    // total_element(head);
    // delete_all_ele(head);
    while(1){
        printf("\n\n");
        printf("Press 1 for CreateNode \nPress 2 for Push \nPress 3 for Pop \nPress 4 for display the stack \nPress 5 for Total Element present in the stack \nPress 6 for deleting all the elements form the stack \nPress 7 to exit from the program \n");
        int data;
        int choice; printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter data: "); 
                scanf("%d",&data);
                node head = create_node(data);
                display(head);
                break;
            case 2:
                printf("Enter data: "); 
                scanf("%d",&data);
                head = push(head, data);
                display(head);
                break;
            case 3:
                head = pop(head);
                display(head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                total_element(head);
                break;
            case 6:
                delete_all_ele(head);
                break;
            case 7:
                printf("Terminating from the program.....\n");
                exit(0);
            default:
                printf("Please enter an valid input !");
        }
    }
}