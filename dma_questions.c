// This is the dynamic memory allocation program.....
/*
    The question is....
    Allocate memory for 500 integers using calloc & then store first 500 natural numbers in that space.
*/

// Including the header files
#include<stdio.h>
#include<stdlib.h>

// declairing the main method
int main(void){

    // creating a pointer ptr
    int *ptr;

    // creating the callock
    ptr = (int *)calloc(500, sizeof(int));

    // Checking the memory allocation is failed or not ?
    if(ptr == NULL){
        printf("Memory allocation failed !!\n");
        return 1;
    }

    // We have to increment the ptr[i] because we are allocating the memory by calloc and by default calloc stores 0 so it will print 0....
    for(int i = 0; i < 500; i++){
        ptr[i] = i + 1; // Incrementing the value here....
    }

    // finally printing the value
    for(int i = 0; i < 500; i++){
        printf("%d\t",ptr[i]);
    }
    return 0;
}