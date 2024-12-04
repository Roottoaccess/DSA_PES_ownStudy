// Defining the header files
#include<stdio.h>
#include<stdlib.h>

// creating the structure

typedef struct poly{
    int coff;
    int power;
    struct poly *link;
}*poly;


// creating the first node
poly create_node(int coff, int power){
    poly n = (poly) malloc (sizeof(poly));

    if(n == NULL){
        printf("Memory allocation failed !");
    }

    n -> coff = coff;
    n -> power = power;
    n -> link = NULL;

    return n;
}

poly insert_node(poly n, int coff, int power){
    poly new_node = create_node(coff, power);
    // insert in the beginning
        if(new_node -> power > n -> power){
            new_node -> link = n;
            return new_node;
    }
    if(power == n -> power){
        n -> coff += coff;
        free(new_node);
        return n;
    }

    poly temp = n;
    while(temp -> link != NULL)
    {
        if(temp -> link -> power == new_node -> power){
            temp -> link -> coff += coff;
            free(new_node);

            return n;
        }

        if(temp -> link -> power > new_node -> link){
            temp = temp -> link;
        }
    }
    new_node -> link = temp -> link;
        temp -> link = new_node;
        return n;
}


// display the node from the head
void display(poly n){
    if(n == NULL){
        printf("There is no node present in the memory !!");
    }
    printf("HEAD -> ");
    while(n != NULL){
        printf("(%d X ^ %d) ", n -> coff, n -> power);
        n = n -> link;
    }
    printf(" = 0 -> NULL \n");
}

poly add_poly(poly n, poly n2) {
    poly temp = n;
    poly temp2 = n2;
    poly list = NULL;
    while (temp != NULL && temp2 != NULL)
    {
        if(temp->power == temp2->power){
            int coff = (temp->coff + temp2->coff);
            int pow = temp->power;
            if (list == NULL)
            {
                list = create_node(coff, pow);
            }else {
            list = insert_node(list, coff, pow);

            }
        }else if (temp->power > temp2->power)
        {
            if (list == NULL)
            {
                list = create_node(temp->coff, temp->power);
            }else {
            list = insert_node(list, temp->coff, temp->power);
            }
            list = insert_node(list, temp2->coff, temp2->power);
        }else {
            if (list == NULL)
            {
                list = create_node(temp2->coff, temp2->power);
            }else {
            list = insert_node(list, temp2->coff, temp2->power);
            }
            list = insert_node(list, temp->coff, temp->power);
        }
            temp = temp->link;
            temp2 = temp2->link;
    }

    while (temp != NULL)
    {
        list = insert_node(list, temp->coff, temp->power);
        temp = temp->link;
    }
    while (temp2 != NULL)
    {
        list = insert_node(list, temp2->coff, temp2->power);
        temp2 = temp2->link;
    }

    return list;
}

// calling the main function
int main(void){
    poly n = create_node(3,6);
    // display(n);
    n = insert_node(n, 3,5);
    // display(n);
    n = insert_node(n, 5,6);
    // display(n);
    // n = insert_node(n, 2, 4);
    // display(n);
    n = insert_node(n, 1, 2);
    display(n);
    // n = insert_node(n, 2, 5);
    // display(n);
    poly n2 = create_node(2, 6);
    n2 = insert_node(n2, 5 , 5);
    n2 = insert_node(n2, 1 , 5);
    // n2 = insert_node(n2, 4 , 8);
    n2 = insert_node(n2, 7 , 2);

    display(n2);
    n = add_poly(n , n2);
    display(n);
}