#include<stdio.h>
#include<stdlib.h>

int main(void){

    int *arr = NULL;
    arr = (int *)calloc(5, sizeof(int));

    if(arr == NULL){
        printf("Memory allocation failed !");
    }

    for(int i = 0; i < 5; i++){
        printf("%d ",arr[i]);
    }

    arr = (int *)realloc(arr, 10 * sizeof(int));

    if(arr == NULL){
        printf("Memory reallocation failed using realloc. \n");
    }

    for(int i = 5; i < 10; arr[i++] = i + 1);

    for(int i = 0; i < 10; i++){
        printf("%d ",arr[i]);
    }

    
}