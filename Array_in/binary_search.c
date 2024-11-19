// This is the binary searching program..
#include<stdio.h>

void binary_searching(int arr[], int lmt){
    int temp = 0;
    for(int i = 0; i < lmt - 1; i++){
        for(int j = 0; j < lmt -1 ; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }   
    printf("After sorting....\n");
    for(int i = 0; i < lmt; i++){
        printf("%d\n",arr[i]);
    }
    int key; printf("Enter the key you want to search? ");
    scanf("%d",&key);
    int low = 0;
    int high = lmt - 1;

    while(low < high){
        int middle = (low + high) / 2;

        if(key == arr[middle]){
            printf("Value found in the index: %d\n", middle);
            return;
        } else if(key < arr[middle]){
            high = middle - 1;
        } else{
            low = middle + 1;
        }
    }
    // return -1;
}
// This algorithm run in with the divide and concer rule
int main(void){

    int lmt; printf("What's the limit? ");
    scanf("%d",&lmt);
    int arr[lmt];

    printf("Enter the elements..\n");
    for(int i = 0; i < lmt; i++){
        scanf("%d",&arr[i]);
    }

    binary_searching(arr, lmt);
    return 0;
}