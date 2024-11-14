#include<stdio.h>
#include<stdlib.h>

int main(void){
    
    // Taking the limit from the user....
    int lmt; printf("What's the limit? "); scanf("%d",&lmt);

    // creating the dynamic memory allocation.....
    int *ptr = NULL;

    // Creating a dynamic memory with malloc....
    ptr = (int *)calloc(lmt, sizeof(int));

    // Checking if the memory is initialized or not !
    if(ptr == NULL){
        printf("Memory allocation failed....");
    }

    // Initializing the value by default....
    // for(int i = 0; i < lmt; ptr[i++] = i + 1);

    for(int i = 0; i < lmt; i++){
        scanf("%d",&ptr[i]);
    }
    printf("Your entered elements are.....\n");
    // Displaying the value....
    for(int i = 0; i < lmt; i++){
        printf("%d\t",ptr[i]);
    }
    /* Taking the key from the user */
    int key; printf("\nWhat's the key? "); scanf("%d",&key);
    // Implementing the linear search logic....
    int count = 0;
    for(int i = 0; i < lmt; i++){
        if(key == ptr[i]){
            count++;
        }
    }
    if(count > 0){
        printf("element found %d times !\n",count);
    }else{
        printf("Element not found !\n");
    }

    // Giving the memory back to the heap....
    free(ptr);
}