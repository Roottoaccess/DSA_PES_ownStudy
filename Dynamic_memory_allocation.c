/* This is the most important concept of Pointers and array in C programming so do it well */

// Allocate the memory in the run time

// malloc() -> function
#include<stdio.h>
#include<stdlib.h> // for dinamic memory allocation
int main(void){
    // printf("%d\n", sizeof(int));
    // printf("%d\n", sizeof(float));
    // printf("%d\n", sizeof(char));
    int n;
    printf("What's n? ");
    scanf("%d",&n);
    int *ptr;
    ptr = (int *)calloc(n , sizeof(int));

    // ptr[0] = 1;
    // ptr[1] = 3;
    // ptr[2] = 5;
    // ptr[3] = 7;
    // ptr[4] = 9;
    printf("Enter the elements one by one....\n");
    for(int i = 0; i < 5; i++){
        // printf("%d\n",ptr[i]);
        scanf("%d",&ptr[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("%d\n",ptr[i]);
    }
    // calloc initialized the value with zero by default..
    
    // free() that is allocated using malloc & calloc

    free(ptr);

    // realloc() is memory using the same pointer and size...
    // memory can increase and decrese
    
}