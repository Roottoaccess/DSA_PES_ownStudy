// PROGRAM 2
#include<stdio.h>

int main(void){
    /* Declaring the array */
    int arr[5] = {10, 20, 30, 40, 50};
    /* Declaring the pointer */
    int *ptr = arr;

    for(int i = 0; i < 5; i++){
        printf("Array elements: %d\n",*(ptr + i));
    }
    return 0;
}