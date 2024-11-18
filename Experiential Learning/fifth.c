/* FIFTH PROGRAM */
#include<stdio.h>

void array_average(int arr[], int lmt){
    int sum = 0;
    for(int i = 0; i < lmt; i++){
        sum += arr[i];
    }
    float avg = sum / lmt;
    printf("Average of the array: %f\n",avg);
}

int main(void){

// Declaring the array....
    int lmt; printf("What's the limit? "); scanf("%d", &lmt);
    int arr[lmt];
    printf("Enter the elements one by one....\n");
    for(int i = 0; i < lmt; i++){
        scanf("%d",&arr[i]);
    }
    array_average(arr, lmt);

return 0;
}