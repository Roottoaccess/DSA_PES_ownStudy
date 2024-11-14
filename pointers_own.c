// This are the libraries
#include<stdio.h>
#include<stdlib.h>
// This is the main function
int main(void){

    // creating a pointer
    int *ptr = NULL;
    ptr = (int *)calloc(5, sizeof(int));

    if(ptr == NULL){
        printf("Memory allocation failed !");
    }
    printf("Enter the value one by one.....\n");
    // Accepting the value....
    for(int i = 0; i < 5; i++){
        scanf("%d",&ptr[i]);
    }

    // Now applying the realloc for updating the memory
    ptr = realloc(ptr , 8);

    printf("Enter the value after upgrading the memory size....\n");
    for(int i = 0; i < 8; i++){
        scanf("%d",&ptr[i]);
    }

    printf("Displaying the data one by one.....\n");
    for(int i = 0; i < 5; i++){
        printf("%d\t",ptr[i]);
    }
    // Givin back the memory.....
    free(ptr);
}