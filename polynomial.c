#include<stdio.h>
#include<stdlib.h>

// creating the structure node
typedef struct term{
    int coffe; int pow;
    struct term *link;
}*term;

// create_node

term create_node(){
    // dynamic memory allocation
    term n = (term) malloc (sizeof(term));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    int coffe; printf("Enter the coffe: "); scanf("%d",&n->coffe);
    int pow; printf("Enter the power: "); scanf("%d",&n->pow);

    n->link = NULL;

    return n;
}

// Polynomial build

// displaying the nodes
void display(term n){
    if(n == NULL){
        printf("There is no node present in the memory ");
    }

    while(n != NULL){
        printf("(%d X ^ %d = 0) \n", n -> coffe , n -> pow);

        n = n -> link;
    }
    // printf("(%d X ^ %d) = 0 \n", n -> coffe , n -> pow);
}
int main(void){
    term n = create_node();
    display(n);
}