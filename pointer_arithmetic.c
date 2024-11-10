// This are the pointer arithmetic
#include<stdio.h>
#include<stdlib.h>
/* Increment of pointers */
int main(void){
    int x[] = {2,4,6,8};

    int *ptr = NULL;

    ptr = x;

    // --> Increment operation

    // printf("Before value: %d\n",*ptr);

    // ptr++;

    // printf("After value: %d\n",*ptr); /* It is giving the result based on its size */

    // --> Addition Operation
    // ptr = ptr + 2;

    // printf("Addition value: %d\n",*ptr);


    // --> Sub Operation
    // int *start = x;
    // int *end = x + 4;

    // printf("Pointer difference -> %ld\n",end - start);

    for(int i = 0; i < 4; i++){
        printf("%d",*ptr);
        ptr++; // Move to the next element
    }
}