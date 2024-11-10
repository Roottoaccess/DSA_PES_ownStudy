/* Pointing-to-a-Pointer */

// including the header files
#include<stdio.h>
// declaring the mainfunction
int main(void){
    /* Here we will implement the concept of the pointing to pointers */
    int val = 66;
    // printf("What's val? ");
    // scanf("%d",&val);

    int *p = &val; // Declaring a pointer variable which is pointing to the variable val

    printf("The value which the first pointer 'p' is holding is: %d\n",*p);

    int **pp = &p; // Here I am making another pointer which is pointing to the pointer p itself

    // Now if I am updating the value of val by the changing the value in the second level pointer
    // **pp = 88;

    /* Lets see whats the second pointer is holding the value? */
    printf("The value which the second pointer holding is: %d\n", **pp);
}