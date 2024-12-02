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

// insert polynomial
term ins_polynomial(term n){
    term new_node = create_node();
/*
    1. if pow is greater than exe pow then add at first
    2. if pow is less than exe pow then add in last
    3. if pow is equal then add the coff , free the new node then return head
    4. if pow is not present in the node then we will insert in position between two nods accoding to the pow
*/
    // if(new_node == NULL){
    //     printf("New node creation failed !");
    // }
    // node temp -> n;
    if (new_node != NULL){
        if(new_node -> pow > n -> pow){
            new_node -> link = n;
        }
    }
return new_node;

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
    n = ins_polynomial(n);
    display(n);
}