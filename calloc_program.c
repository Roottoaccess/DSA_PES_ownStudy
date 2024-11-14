// Stack , heap , meta memory (static -> stack) , (dynamic -> heap)
// Declaring the header files
#include<stdio.h>
#include<stdlib.h>
// the main function
int main(void){

    int *arr = NULL;
    // using the calloc function declaring the 5 bit of memory
    arr = (int *)calloc(5, sizeof(int));

    if(arr == NULL){
        printf("Memory allocation failed !");
    }

    for(int i = 0; i < 5; i++){
        printf("%d ",arr[i]);
    }
    // Declaring teh reallock function
    arr = (int *)realloc(arr, 10 * sizeof(int));
    // Checking that if the memory allocation is failed or not ??
    if(arr == NULL){
        printf("Memory reallocation failed using realloc. \n");
    }
    // Displaying the value and initializing the value......
    for(int i = 5; i < 10; arr[i++] = i + 1);

    for(int i = 0; i < 10; i++){
        printf("%d ",arr[i]);
    }
    
}