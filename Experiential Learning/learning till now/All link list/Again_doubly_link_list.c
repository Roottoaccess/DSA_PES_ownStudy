// #include<stdio.h>
// #include<stdlib.h>

// // creating the structure
// typedef struct node{
//     int data;
//     struct node *next;
//     struct node *prev;
// }*node;

// // creating the first node !!
// node create_node(int data){
//     // dynamic memory allocation
//     node n = (node) malloc (sizeof(node));
//     if(n == NULL){
//         printf("Memory alloaction failed !");
//     }

//     n -> data = data;
//     n -> next = NULL;
//     n -> prev = NULL;

//     return n;
// }

// // creating the display function
// void display(node n){
//     if(n == NULL){
//         printf("There is no node present in the memory for display !");
//     }

//     printf("HEAD -> ");
//     while(n != NULL){
//         printf("%d -> ", n -> data);
//         n = n -> next;
//     }
//     printf("NULL \n");
// }

// // // creating the insert_in_the_front
// // node ins_in_front(node n, int data){
// //     // creating the new node
// //     node new_node = create_node(data);

// //     if(new_node == NULL){
// //         printf("New node created failed !");
// //     }

// //     new_node -> next = n;
// //     n -> prev = new_node;
// //     new_node -> prev = NULL;

// //     return new_node;
// // }

// node ins_in_front(node n, int data) {
//     node new_node = create_node(data);
//     if(new_node == NULL) {
//         printf("New node created failed !");
//         return n;  // Return original list if creation failed
//     }
//     new_node->next = n;
//     if(n != NULL) {  // Add this check
//         n->prev = new_node;
//     }
//     new_node->prev = NULL;
//     return new_node;
// }

// // creating the insert_in_last
// node ins_in_last(node n, int data){
//     // again creating the node
//     node new_node = create_node(data);

//     node temp = n;

//     while(temp -> next != NULL){
//         temp = temp -> next;
//     }

//     temp -> next = new_node;
//     new_node -> prev = temp;
//     new_node -> next = NULL;

//     return n;
// }

// // // creating the insert_in_position
// // node ins_in_position(node n, int data, int pos){
// //     // creating the new_node
// //     node new_node = create_node(data);
// //     if(pos == 0){
// //         return ins_in_front(n, data);
// //         // new_node -> next = n;
// //         if(n != NULL){
// //             n -> prev = new_node;
// //         }
// //         n = new_node;
// //         return n;
// //     }
// //     node temp = n;
// //     for(int i = 0; i < pos - 1 && temp != NULL; i++){
// //         temp = temp -> next;
// //     } 
// //     if(temp == NULL || temp -> next == NULL){
// //         return ins_in_last(n, data);
// //     }
// //     new_node -> next = temp -> next;
// //     if(temp -> next != NULL){
// //         temp -> next -> prev = new_node;
// //     }
// //     temp -> next = new_node;
// //     new_node -> prev = temp;

// //     return n;
// // }

// // node ins_in_position(node n, int data, int pos) {

// //     node new_node = create_node(data);
// //     // if(pos == 0) {
// //     //     return ins_in_front(n, data);
// //     // }
    
// //     // node new_node = create_node(data);
// //     if ((pos <= 1) || (n == NULL))
// //     {
// //         new_node->next = n;
// //         if (n != NULL)
// //         {
// //             n->prev = new_node;
// //             n = new_node;
// //         }
// //         return n;
// //     }

// //     // if(new_node == NULL) {
// //     //     return n;
// //     // }
    
// //     node temp = n;
// //     for(int i = 0; i < pos - 1 && temp != NULL; i++) {
// //         temp = temp->next;
// //     }
    
// //     if(temp == NULL || temp->next == NULL) {
// //         return ins_in_last(n, data);
// //     }
    
// //     new_node->next = temp->next;
// //     if(temp->next != NULL) {
// //         temp->next->prev = new_node;
// //     }
// //     temp->next = new_node;
// //     new_node->prev = temp;
// //     return n;
// // }

// node insertAtPos(int data, int req_pos, node head)
// {
//     node new, curr;
//     int curr_pos;
//     new = create_node(data);
//     if (new == NULL)
//     {
//         return head;
//     }

//     if ((req_pos <= 1) || (head == NULL))
//     {
//         new->next = head;
//         if (head != NULL)
//         {
//             head->prev = new;
//             head = new;
//         }
//         return head;
//     }
//     curr = head;
//     curr_pos = 1;
//     while (curr->next != NULL && curr_pos < (req_pos - 1))
//     {
//         curr = curr->next;
//         curr_pos++;
//     }

//     if (curr_pos == req_pos - 1)
//     {
//         new->next = curr->next;
//         new->prev = curr;
//         if (curr->next != NULL)
//         {
//             // alt method
//             //  curr->next = new;
//             //  curr = new->next;
//             //  curr->prev = new;
//             curr->next->prev = new;
//         }
//         curr->next = new;
//     }
//     else
//         printf("invalid position");
//     return head;
// }

// // creating the main function
// int main(void){
//     node head = create_node(2);
//     display(head);
//     head = ins_in_front(head, 4);
//     display(head);
//     head = ins_in_last(head, 8);
//     display(head);
//     // head = ins_in_position(head, 5, 0);
//     head = insertAtPos(12, 0, head);
//     display(head);
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *Node;

Node createNode(int data)
{
    Node new = (Node)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Mem allocation failed\n");
        exit(0);
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

// insert at first of the dll
Node insertAtFirst(int data, Node head)
{
    Node new = createNode(data);
    if (head == NULL)
    {
        return new;
    }
    // new->prev = head->prev;
    new->next = head;
    head->prev = new;
    return new;
}

// display the dll
void display(Node head)
{
    Node curr;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\n\nHEADER--> ");
    for (curr = head; curr != NULL; curr = curr->next)
    {
        printf("[%d]-->", curr->data);
    }
    printf("NULL\n\n");
}

// reverse print the dll
void reverseDisplay(Node head)
{
    Node curr;
    if (head == NULL)
        return;
    // going to the last node
    curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    // traversing backward using prev pointer
    printf("Reversed Head-->");
    while (curr != NULL)
    {
        printf("[%d]-->", curr->data);
        curr = curr->prev;
    }
    printf("NULL\n\n");
}

// insert at end in dll
Node insertAtEnd(int data, Node head)
{
    Node new, curr;
    new = createNode(data);
    if (head == NULL)
    {
        return new;
    }
    curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new;
    new->prev = curr;
    return head;
}

// insert at given position
Node insertAtPos(int data, int req_pos, Node head)
{
    Node new, curr;
    int curr_pos;
    new = createNode(data);
    if (new == NULL)
    {
        return head;
    }

    if ((req_pos <= 1) || (head == NULL))
    {
        new->next = head;
        if (head != NULL)
        {
            head->prev = new;
            head = new;
        }
        return head;
    }
    curr = head;
    curr_pos = 1;
    while (curr->next != NULL && curr_pos < (req_pos - 1))
    {
        curr = curr->next;
        curr_pos++;
    }

    if (curr_pos == req_pos - 1)
    {
        new->next = curr->next;
        new->prev = curr;
        if (curr->next != NULL)
        {
            // alt method
            //  curr->next = new;
            //  curr = new->next;
            //  curr->prev = new;
            curr->next->prev = new;
        }
        curr->next = new;
    }
    else
        printf("invalid position");
    return head;
}

// reverse the dll
Node reverseList(Node head)
{
    Node temp = NULL;
    Node curr = head;

    // swap next and prev for all nodes in the list
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        // move to next node (which is the previous node before swapping)
        curr = curr->prev;
    }

    // before changing head, check for the cases like empty list with only one node;
    if (temp != NULL)
    {
        head = temp;
    }

    return head;
}

// Function to reverse the DLL recursively
Node reverseRecursive(Node head)
{
    // Base case: if the list is empty or has only one node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Recursively reverse the sublist starting from the second node
    Node rest = reverseRecursive(head->next);

    // Backtracking: swap the next and prev pointers
    head->next->prev = NULL; // Set the prev of the second node to NULL
    head->next->next = head; // Set the next of the second node to the first node
    head->next = NULL;       // Set the next of the first node to NULL

    return rest; // Return the new head of the reversed list
}

// delete at front
Node deleteAtfront(Node head)
{
    Node temp;
    if (head == NULL)
    {
        printf("\nEmpty List");
        return head;
    }
    if (head->next == NULL)
    {
        printf("Deleted node is: [%d]", head->data);
        free(head);
        return NULL;
    }
    temp = head;
    head = head->next;
    head->prev = NULL;
    printf("Deleted node is: [%d]", temp->data);
    free(temp);
    return head;
}

// delete at end
Node deleteAtEnd(Node head)
{
    Node temp;
    if (head == NULL)
    {
        printf("\nEmpty List");
        return head;
    }
    if (head->next == NULL)
    {
        printf("Deleted note is: [%d]", head->data);

        return NULL;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Deleted data is: [%d]", temp->data);
    temp->prev->next = NULL;
    free(temp);
    return head;
}

// delete at position
Node deleteAtPosition(int req_pos, Node head)
{
    Node temp, curr;
    int curr_pos;
    if (head == NULL)
    {
        printf("\nList is empty");
        return head;
    }
    // if data to deleted is at first position
    if (req_pos <= 1)
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("Deleted data is: [%d]", temp->data);
        free(temp);
        return head;
    }

    curr = head;
    curr_pos = 1;

    // traverse to the node just before the one to be deleted
    while (curr != NULL && curr_pos < req_pos - 1)
    {
        curr = curr->next;
        curr_pos++;
    }

    // if node to deleted doesnt exist or is beyond the list
    // i.e  If curr is NULL, it means the list is shorter than req_pos - 1. If curr->next is NULL, it means req_pos is beyond the end of the list.

    if (curr == NULL || curr->next == NULL)
    {
        printf("\nPosition not Found");
        return head;
    }
    temp = curr->next;
    curr->next = temp->next;
    temp->next->prev = curr;
    printf("Deleted data is: [%d]", temp->data);
    free(temp);
    return head;
}

// to insert a node in order(used by sort function)
//  Node insertInORDER(Node new, Node head)
//  {
//      Node temp;
//      if (head == NULL)
//      {
//          head = new;
//          return head;
//      }
//      if (new->data < head->data)
//      {
//          new->next = head;
//          head->prev = new;
//          head = new;
//      }
//      else
//      {
//          temp = head;
//          // while ((temp->next != NULL) && (new->data > temp->next->data))
//          // {
//          //     //prev = temp;
//          //     temp = temp->next;
//          // }
//          // new->next = temp->next;
//          // if(temp->next != NULL){
//          //     temp->next->prev = new;
//          // }
//          // temp->next = new;
//          // new->prev = temp;
//          while(temp != NULL && new->data > temp->data){
//              temp = temp->next;
//          }
//          temp->prev->next = new;
//          new->prev = temp->prev;
//          temp->prev = new;
//          new->next = temp;
//      }
//      return head;
//  }

Node insertInORDER(Node new, Node head)
{
    Node temp;
    if (head == NULL)
    {
        head = new;
        return head;
    }
    if (new->data < head->data)
    {
        new->next = head;
        head->prev = new;
        head = new;
    }
    else
    {
        temp = head;
        while (temp != NULL && new->data > temp->data)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            // Insert at the end of the list
            Node last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = new;
            new->prev = last;
        }
        else
        {
            // Insert in the middle of the list
            new->prev = temp->prev;
            temp->prev->next = new;
            new->next = temp;
            temp->prev = new;
        }
    }
    return head;
}

Node sortList(Node head)
{
    Node new_head = NULL;
    Node temp;
    if (head == NULL)
    {
        printf("\n Empty List");
        //return head;
    }
    // new_head = head;
    // head = head->next;
    // new_head->prev = NULL;
    // new_head->next = NULL;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        temp->prev = NULL;
        new_head = insertInORDER(temp, new_head);
    }
    return new_head;
}

// delete by content
Node deleteContent(int search_id, Node head)
{
    Node curr;
    if (head == NULL)
    {
        printf("\nList empty");
    }
    if (head->data == search_id)
    {
        printf("Deleted node is: [%d]", head->data);
        head = head->next;
        return head;
    }

    curr = head;
    while (curr->next != NULL && curr->data != search_id)
    {
        curr = curr->next;
    }
    if (curr->data == search_id)
    {
        curr->prev->next = curr->next;
        printf("Deleted node is: [%d]", curr->data);
        free(curr);
    }
    else
        printf("\nSpecified Id not found\n");
    return head;
}

// count number of nodes
int count_node(Node head)
{
    Node temp;
    int count;
    if (head == NULL)
    {
        printf("\nEmpty List");
        //return 0;
    }
    temp = head;
    for (count = 0; temp != NULL; count++)
    {
        temp = temp->next;
    }
    return count;
}

int main()
{
    Node head = NULL;

    head = createNode(10);
    head = insertAtFirst(1, head);
    head = insertAtEnd(40, head);
    head = insertAtEnd(50, head);
    head = insertAtEnd(30, head);

    display(head);

    

    // head = reverseList(head);
    // head = reverseRecursive(head);

    // display(head);

    // head = deleteContent(50, head);

    head = sortList(head);
    int count = count_node(head);
    printf("count is: [%d]", count);

    display(head);

    head = insertAtPos(12, 0, head);
    display(head);
}