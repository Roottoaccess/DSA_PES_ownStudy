#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void LinkListTraverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Elements: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(void){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocating memory for nodes in the linked list in Heap
    head = (struct Node *) malloc(sizeof(struct Node));
    return 0;
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    
    // Link first and second node
    head->data = 7;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 18;
    third->next = NULL;

    LinkListTraverse(head);
    return 0;

    printf("Hello c");
}