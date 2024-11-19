// This are the header files......
#include<stdio.h>
#include<stdlib.h>
/* This is the dynamic memory allocation program */
int main(){
    // This is the limit for the array....
    int lmt; printf("What's the limit? "); scanf("%d",&lmt);
    /* Creating the pointer */
    int *ptr;
    ptr = (int *)malloc(lmt * sizeof(int)); // Dynamic memory allocation

    // Checking if the memory properly allocated or not....
    if(ptr == NULL){
        printf("Memory allocation failed !!");
        return 1;
    }
    printf("Enter the elements one by one.....\n"); // Accepting the value....
    for(int i = 0; i < lmt; i++){
        scanf("%d",&ptr[i]);
    }
    // Displaying the value....
    printf("Displaying the array.....\n");
    for(int i = 0; i < lmt; i++){
        printf("%d\t",ptr[i]);
    }
    // This is the new limit declaration....
        int new_limit; printf("\nWhat's the new limit? "); scanf("%d",&new_limit);
    // Using the realloc function creating more memory space....
        ptr = (int *)realloc(ptr , new_limit * sizeof(int)); // Realloc function for allocating extra memory

        if(ptr == NULL){ // Checking if the memory elements is allocated successfully or not.....
            printf("Memory reallocation failed !");
        }

        // Addiding the extra elements.....
        if(new_limit > lmt){
            printf("Enter the additional elements: ");
            for(int i = lmt; i < new_limit; i++){
                scanf("%d", &ptr[i]);
            }
        }
        // This is the final array....
        printf("Displaying the updated array....\n");
        for(int i = 0; i < new_limit; i++){
            printf("%d\t",ptr[i]);
        }

    free(ptr); // Giving the memory back..

    return 0; // Returning 0....
}
