#include<stdio.h>
#include<stdlib.h>

int main(void){

    int *ptr;

    int n; printf("What's n? "); scanf("%d",&n);

    // creating the calloc for dynamic memory allocation....
    ptr = (int *)calloc(n, sizeof(int));

    // checking if the memory allocation is assigned or not ?
    if(ptr == NULL){
        printf("failed to allocate the memory !");
    }

    /* Taking the valur from the user */
    printf("Enter the value one by one.....\n");

    for(int i = 0; i < n; i++){
        scanf("%d",&ptr[i]);
    }


    printf("Displaying the value......\n");

    for(int i = 0; i < n; i++){ // Displaying the value.....
        printf("%d\t", ptr[i]);
    }

    printf("\nEnter the value you want to find? \n");

    int find; printf("What's find? "); scanf("%d",&find); // finding the value....
    int count;
    for(int i = 0; i < n; i++){ // Logic for searching the value(Linear search)
        if(find == ptr[i]){
            count++;
        }
    }
    /* condition if the counter variable is greater than 0 then it will go inside the if block or otherwise it will print the else part */ 
    
    if(count > 0){
        printf("We got the value in the location: %p\n",ptr);
    }else {
        printf("We could not found the value in the memory....\n");
    }

    free(ptr); // releasing the memory.....
    return 0;
}