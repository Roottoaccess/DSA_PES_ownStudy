// This is program for linear searching in array
#include<stdio.h>
#include<stdlib.h>
int main(void){

    // This is the linear search program..
    int lmt;
    printf("What's the limit? "); scanf("%d",&lmt);

    // Using the dynamic memory allocation
    int *ptr;
    ptr = (int *)malloc(lmt * sizeof(int));
    printf("Enter the value one by one...\n");
    for(int i = 0; i < lmt; i++){
        scanf("%d",ptr);
    }

    // Applying the logic in the program....

    /* Setting the key */
    int key; printf("Enter your key? ");
    scanf("%d",&key);

    int count = 0; // This is a counter variable
    for(int i = 0; i < lmt; i++){
        if(ptr[i] == key){
            count++;
        }
    }
    if(count > 0){
        printf("Congo you have unlocked the Encryption.. %d times\n",count);
    } else {
        printf("Sorry we can't encrypt the code....\n");
    }

    free(ptr); // Giving back the value..
    return 0;
}