// Circular link list program :-
#include<stdio.h>
#include<stdlib.h>

// creating the struct
typedef struct node{
    int data;
    struct node *link;
}*node;


// creating node function
node create_node(int data){
    // dynamic memory allocation
    node n = (node) malloc (sizeof(node));

    // if(n == NULL){
    //     printf("Memory allcation failed !");
    // }

    n -> data = data;
    n -> link = n;

    return n;
}

// display function
void display(node n){
    if(n == NULL){
        printf("There is no node present to display in the memory !");
    }

    printf("Head -> ");
    node temp = n;
    do{
        printf("%d -> ", temp -> data);
        temp = temp -> link;
    }while(temp != n);
    printf("NULL \n");
}

// inserting at the front
node ins_in_front(node n, int data){
    // creating the new node
    node new_node = create_node(data);

    // if(new_node == NULL){
    //     printf("New node not created !");
    // }

    node temp = n;
    do{
        temp = temp -> link;
    }while(temp -> link != n);

    temp -> link = new_node;
    new_node -> link = n;

    return new_node;
}

// insert at the last
node ins_at_last(node n, int data){
    node new_node = create_node(data);

    node temp = n;

    do{
        temp = temp -> link;
    }while(temp -> link != n);

    // printf("%d",temp -> data);
    // return 0;

    temp -> link = new_node;
    new_node -> link = n;

    return n;
}

// delete in the front
node delete_front(node n){
    node temp = n;

    do{
        temp = temp -> link;
    }while(temp -> link != n);

    node demo = n;

    temp -> link = demo -> link;
    n = demo -> link;
    
    free(demo);

    return n;
}

// delete in the rare
node delete_rare(node n){
    node temp = n;

    do{
        temp = temp -> link;
    }while(temp -> link -> link != n);

    node demo = temp -> link;

    temp -> link = n;

    free(demo);

    return n;
}

// insert in the position
node ins_position(node n, int data, int pos){
    node new_node = create_node(data);

    node temp = n;
    if(pos == 0){
        return ins_in_front(n, data);
    }

    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
        // if(pos > sizeof(n)){
        //     printf("Position Exclude");
        // }
    }

    if(temp -> link == n){
        return ins_at_last(n, data);
    }

    new_node -> link = temp -> link;
    temp -> link = new_node;

    return n;
}

node delete_position(node n, int pos){
    if(pos == 0){
        return delete_front(n);
    }
    node temp = n;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> link;
    }

    if(temp -> link == n){
        return delete_rare(n);
    }
    node demo = temp -> link;
    temp -> link = temp -> link -> link;
    free(demo);
    return n;
}

// creating the main function
int main(void){
    printf("\n\t\t\t\t Give your choice \n\n");

    int data, pos;
    node head = NULL;

while(1){
    printf("\n\n Press 1 for creating the node \n Press 2 for display \n Press 3 for insert none in front \n Press 4 for insert node in rare \n Press 5 for deleting node in the front \n Press 6 for deleting node in the rare \n Press 7 for inserting node in position \n Press 8 for deleting the node in the position\n Press 9 for exiting\n");
int choice; printf("Enter your choice: "); scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the data: "); scanf("%d",&data);
            head = create_node(data);
            break;

        case 2:
            display(head);
            break;

        case 3:
            printf("Enter the data: "); scanf("%d",&data);
            head = ins_in_front(head, data);
            break;
        case 4:
            printf("Enter the data: "); scanf("%d",&data);
            head = ins_at_last(head, data);
            break;
        case 5:
            head = delete_front(head);
            break;

        case 6:
            head = delete_rare(head);
            break;

        case 7:
            printf("Enter the data: "); scanf("%d\n",&data);
            printf("Enter the position: "); scanf("%d",&pos);
            head = ins_position(head, data, pos);
            break;
        
        case 8:
            printf("Enter the position: "); scanf("%d",&pos);
            head = delete_position(head, pos);
            break;

        case 9:
            printf("Exiting the program......\n");
            exit(0);
        
        default:
            printf("Wrong Input Given !");
        }
    }    
    return 0;
}