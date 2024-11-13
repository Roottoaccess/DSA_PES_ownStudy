#include<stdio.h>
#include<stdlib.h>
int main(void){
    // int *intPointer;
    // char *charPointer;
    // void *voidPointer;

    // printf("size of the pointer: %zu bytes\n",sizeof(intPointer));
    // printf("size of the pointer: %zu bytes\n",sizeof(charPointer));
    // printf("size of the pointer: %zu bytes\n",sizeof(voidPointer));

    int *ptr= NULL;
    ptr = (int *)malloc(5 * sizeof(int));

    if(ptr == NULL){
        printf("Memory Allocation failed !");
        return 1;
    }
    for(int i = 0; i < 5; ptr[i++] = i + 1); // assignment of the value here only
    // and incrementing it also......
    for(int i = 0; i < 5; i++){
        printf("%d\n", ptr[i]);
    }
    free(ptr);
    return 0;
    

}