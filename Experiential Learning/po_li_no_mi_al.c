// This is a program for the polynomials
#include<stdio.h>
#include<stdlib.h>

// creating the structure

typedef struct node{
    int coff;
    int pow;
    struct node *link;
}*node;

// create node function
node create_node(int coff, int pow){
    // Dynamic memory allocation
    node n = (node) malloc (sizeof(node));
    // checking if the memory allocation is established or not
    if(n == NULL){
        printf("Memory allocation failed !");
    }
    // Assigning the values
    n -> coff = coff;
    n -> pow = pow;
    n -> link = NULL;

    return n;
}
// creating the insert function
node insert_node(node n, int coff, int pow){
    // creating a new node
    node new_node = create_node(coff, pow);

    if(new_node == NULL){
        printf("New node not created !");
    }

    if(new_node -> pow > n -> pow){
        // applying the insert first logic
        new_node -> link = n;
        return new_node;
    }

    if(pow == n -> pow){
        n -> coff += coff;

        free(new_node);
        return n;
    }
    node temp = n;
    while(temp -> link != NULL)
    {
        if(temp -> link -> pow == new_node -> pow){
            temp -> link -> coff += coff;
            free(new_node);
            return n;
        }

        if(temp -> link -> pow > new_node -> pow){
            temp = temp -> link;
        }
    }
        new_node -> link = temp -> link;
        temp -> link = new_node;
        return n;
}




// display function to display the link-list

void display(node n){
    if(n == NULL){
        printf("There is no node present in the memory to display !");
    }
    printf("HEAD -> ");
    while(n != NULL){
        printf("(%d X ^ %d) ", n -> coff , n -> pow);
        n = n -> link;
    }

    printf(" = 0 -> NULL \n");
}

// creating the main function for calling
int main(void){
    node n = create_node(4,5);
    // display(n);
    n = insert_node(n, 3, 5);
    // display(n);
    n = insert_node(n, 2, 2);
    // display(n);
    n = insert_node(n, 3, 2);
    display(n);
}