#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *ptr;

    ptr = (int *) calloc(5 , sizeof(int));

    printf("Enter (5) elements one by one.....\n");
    for(int i = 0; i < 5; i++){
        scanf("%d",&ptr[i]);
    }

    ptr = realloc(ptr, 8);
    printf("Enter (8) elements one by one.....\n");
    for(int i = 0; i < 8; i++){
        scanf("%d",&ptr[i]);
    }

    printf("Your elements are.....\n");

    for(int i = 0; i < 8; i++){
        printf("number %d is %d\n",i,ptr[i]);
    }
    free(ptr);
}