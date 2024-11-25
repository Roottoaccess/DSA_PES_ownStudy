// Linklist program
#include<stdio.h>
#include<stdlib.h>

typedef struct myNode{

    int data;
    struct myNode *link;
    
} *Node;

// creating a function to create the first node....
Node create_node(int data){
    // Dynamic memory allocation..
    Node temp = (Node)malloc(sizeof(Node));

    if(temp != NULL){
        temp -> data = data;
        temp -> link = NULL;
    } else {
        printf("\n \t Unable to create the node !");
    }
    return temp;
}

// Creating a Display function for Displaying the node from the Head means from the starting point..
void display(Node Head){
    if(Head == NULL){
        printf("Empty list !");
    } else {
        printf("HEAD -> ");

        for(Node temp = Head; temp != NULL; temp = temp -> link){
            printf("%d -> ", temp->data);
        }
        printf(" NULL \n");
    }
}

// Inserting the data in the front....
Node ins_front(Node Head, int data){
    Node new_node = create_node(data);

    if(new_node != NULL){
        new_node -> link =  Head;
        Head = new_node;
    }
    return new_node;
}

// Delete the data in the front....
Node del_front(Node Head){
    Node temp;
    if(Head == NULL){
        printf("\n\t\t Empty list");
    } else {
        temp = Head; Head = Head -> link;
        printf("\n Deleting %d \n", temp -> data);
        free(temp);
    }
    return Head;
}

// Inserting in the last !!
Node ins_last(Node Head, int data){
    Node temp, new_node = create_node(data);
    if(new_node != NULL){
        if(Head == NULL){
            return new_node;
        }
        for(temp = Head; temp->link!=NULL; temp=temp->link)
        ;
            temp->link = new_node;
    }
    return Head;
}

// Deleting in the last !!
Node Delete_Last(Node Head){
    if(Head == NULL){
        printf("\n\t\t Empty List");
        return NULL;
    }
    if(Head->link == NULL){
        printf("\n\t Deleted node %d ",Head->data);
        free(Head); return NULL;
    }
    Node curr = Head;
    while(curr -> link -> link != NULL){
        curr = curr->link;  
    }
    printf("Deleted node %d \n",curr->link->data);
    free(curr->link);
    curr->link = NULL;
    return Head;
}

// Insertion in position
Node insert_at_position(Node Head, int data, int pos) {
    Node curr = Head;
    // int i = 0;

    // Traverse the list to find the position
    for (int i = 0; curr != NULL && i < pos - 1; i++) {
        curr = curr->link;
    }

    // Check if the position is out of range
    if (curr == NULL) {
        printf("Out of range. Not inserted.\n");
        return Head;
    }

    // Create a new node
    Node new_node = create_node(data);
    if (new_node != NULL) 
    {
        // Adding element in between in this operation
        new_node->link = curr->link;
        curr->link = new_node;
    } else {
        printf("Memory allocation failed. Not inserted.\n");
    }

    return Head;
}


Node insert_in_sorted_list(Node Head, int data){
    Node curr = Head, new_node = create_node(data);

    if (new_node == NULL){
        return Head;
    }

    if(Head == NULL || Head -> data >= data){
        new_node -> link = Head;
        return new_node;
    }
    while(curr -> link != NULL && curr -> link -> data < data){
        curr = curr -> link;
    }

    new_node -> link = curr -> link;
    curr -> link = new_node;

    return Head;
}

Node delete_position(Node Head, int pos){
    if(Head == NULL){
        printf("\n\t\tEmpty List, Cannot delete.");
        return NULL;
    }
    if(pos == 0){
        Node temp = Head;
        Head = Head -> link;
        printf("\n\tDeleted Node %d",temp->data);

        free(temp);
        return Head;
    }
    Node curr = Head;
    for (int i = 0; curr -> link != NULL && i < pos - 1; i++)
        curr = curr -> link;

    if(curr->link == NULL){
        printf("\n\tOut of range. Node not found.");

        return Head;
    }
    Node temp = curr->link;
    curr->link = temp->link;
    printf("\n\tDeleted Node %d",temp->data);
    free(temp);

    return Head;
}

Node reverse_list(Node Head){
    Node new_head = NULL;
    int data;
    while(Head != NULL){
        data = Head->data;
        Head = del_front(Head);
        new_head = ins_front(new_head, data);
    }
    return new_head;
}
Node sort_list(Node Head){
    Node sorted_head = NULL;
    int data;

    while(Head != NULL){
        int data = Head->data;
        Head = del_front(Head);
        sorted_head = insert_in_sorted_list(sorted_head, data);
    }
    return sorted_head;
}

Node merge_sorted_lists(Node Head1, Node Head2){
    while (Head2 != NULL){
        int data = Head2->data;
        Head2 = del_front(Head2);
        Head1 = insert_in_sorted_list(Head1, data);
    }
    return Head1;
}

// calling the main function.....
int main(void){
    
    // Calling the function....
    Node Head = NULL;
    int num;
    int pos;
    while(1){
        printf("\t\tPlease give your choice.. \n 1 for create node \n 2 for display node \n 3 for insert in front node \n 4 for delete in front node \n 5 for inserting in last node \n 6 deleting in last node \n 7 insert at position node \n 8 insert in sorted list \n 9 deleting at position node \n 10 Reverse the list \n 11 Sorted List \n 12 Merge sorted lists \n 13 Exit \n");

        int choice; printf("Enter your choice: "); scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the num? "); scanf("%d",&num);
                Head = create_node(num);
                continue;
            case 2:
                display(Head);
                continue;
            case 3:
                printf("Enter the num? "); scanf("%d",&num);
                Head = ins_front(Head, num);
                continue;
            case 4:
                Head = del_front(Head);
                continue;
            case 5:
                printf("Enter the num? "); scanf("%d",&num);
                Head = ins_last(Head, num);
                continue;
            case 6:
                Head = Delete_Last(Head);
                continue;
            case 7:
                printf("Enter the num? "); scanf("%d",&num);
                printf("What's the position? "); scanf("%d",&pos);
                Head = insert_at_position(Head, num, pos);
                continue;
            case 8:
                printf("Enter the num? "); scanf("%d",&num);
                Head = insert_in_sorted_list(Head, num);
                continue;
            case 9:
                printf("Enter the position? "); scanf("%d",&pos);
                Head = delete_position(Head, pos);
                continue;
            case 10:
                Head = reverse_list(Head);
                continue;
            case 11:
                Head = sort_list(Head);
                continue;
            case 12:
                Head = merge_sorted_lists(Head, Head);
                continue;
            case 13:
                break;
            default:
                printf("Entered wrong input");
        }
        return 0;
    }
}