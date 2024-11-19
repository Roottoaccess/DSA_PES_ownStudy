// This is the program for finding the largest value from the array..

#include<stdio.h>

int main(void){

    int lmt; printf("What's the limit? ");
    scanf("%d",&lmt);

    int arr[lmt];

    printf("Enter the elements one by one....\n");
    for(int i = 0; i < lmt; i++){
        scanf("%d",&arr[i]);
    }
    int largest = arr[0];
    int smallest = arr[0];
    // applying the logic
    for(int i = 0; i < lmt; i++){
        if(smallest > arr[i]){
            smallest= arr[i];
        }
    }
    for(int i = 0; i < lmt; i++){
        if(largest < arr[i]){
            largest= arr[i];
        }
    }

    printf("The smallest element from the array is: %d\n",smallest);
    printf("The largest element from the array is: %d\n",largest);
}